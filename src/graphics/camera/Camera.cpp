/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include <thread>
#include <functional>

namespace Rtx {
    std::atomic<int> Camera::totalLinesProcessed(0);
    std::mutex Camera::totalLinesMutex;
    std::atomic<int> Camera::threadFinished(0);

    Camera::Camera(
        Math::Vec3 cameraCenter,
        int imageWidth,
        RenderMode renderMode,
        Math::Vec3 lookAt,
        double fov,
        double samplesPerPixel
    ) {
        this->_lookAt = lookAt;
        this->fov = fov;
        this->_samplesPerPixel = samplesPerPixel;
        this->_cameraCenter = cameraCenter;
        this->_imageWidth = imageWidth;
        this->_renderMode = renderMode;
        this->_imageHeight = static_cast<int>(_imageWidth / _aspectRatio);
        if (_imageHeight < 1)
            _imageHeight = 1;

        this->_pixels.clear();
        this->_pixels.reserve(_imageWidth * _imageHeight * 4);

        if (_renderMode == RenderMode::SFML)
            this->_display = std::make_shared<SfmlDisplay>(_imageWidth, _imageHeight);
        this->init();
    }

    //TODO: Refactor by not stocking in the class variables who are only used once
    void Camera::init() {
        double focalLength = (this->_cameraCenter - this->_lookAt).length();
        double theta = fov * M_PI / 180;
        double ratio = tan(theta / 2);

        this->_viewportHeight = 2.0 * ratio * focalLength;
        this->_viewportWidth = _viewportHeight * (double(_imageWidth) / _imageHeight);

        Math::Vec3 w = (this->_cameraCenter - this->_lookAt).unitVector();
        Math::Vec3 u = this->_upVector.cross(w).unitVector();
        Math::Vec3 v = w.cross(u);

        this->_viewportU = u * this->_viewportWidth;
        this->_viewportV = -v * this->_viewportHeight;

        this->_pixelDeltaU = this->_viewportU / _imageWidth;
        this->_pixelDeltaV = this->_viewportV / _imageHeight;

        this->_viewportUpperLeft = _cameraCenter - (w * focalLength) - this->_viewportU / 2 - this->_viewportV
                                                                                              / 2;
        this->_pixel00Loc = this->_viewportUpperLeft + (( this->_pixelDeltaU + this->_pixelDeltaV) * 0.5);
    }

    Color Camera::castRay(int x, int y, ObjectList &objects) {
        Math::Vec3 offset = Math::Vec3(Utils::Randomizer<double>::getRandom() - 0.5,Utils::Randomizer<double>::getRandom() - 0.5, 0);
        Math::Vec3 pixelSample = this->_pixel00Loc + this->_pixelDeltaU * (x + offset.x()) + this->_pixelDeltaV * (y
            + offset.y());
        Math::Vec3 direction = pixelSample - _cameraCenter;
        Ray3D ray(_cameraCenter, direction);

        return ray.color(objects, backgroundColor);
    }

    void Camera::generateImage(ObjectList &objects) {
        fillUint8Array(objects);
        std::cout << "P3\n" << _imageWidth << ' ' << _imageHeight << "\n255\n";
        for (int i = 0; _pixels.size() > i; i += 4) {
            Color pixelColor(_pixels[i] / 256.0, _pixels[i + 1] / 256.0, _pixels[i + 2] / 256.0, _pixels[i + 3]);
            pixelColor.writeColor(std::cout);
        }
    }

    void Camera::fillUint8Array(ObjectList &objects) {
        const int numThreads = std::thread::hardware_concurrency();
        const int rowsPerThread = _imageHeight / numThreads;
        std::vector<std::thread> threads;
        std::vector<sf::Uint8> pixels(_imageWidth * _imageHeight * 4);
        int mode = this->_renderMode == RenderMode::SFML ? 0 : 1;

        for (int t = 0; t < numThreads - 1; ++t) {
            int startRow = t * rowsPerThread;
            int endRow = (t + 1) * rowsPerThread;
            threads.emplace_back(std::bind(
                &Camera::fillPixelsThread, this, startRow,endRow, _imageWidth, _samplesPerPixel, std::ref(objects),
                std::ref(pixels), std::ref(_display), mode));
        }
        int startRow = (numThreads - 1) * rowsPerThread;
        int endRow = _imageHeight;

        threads.emplace_back(std::bind(
            &Camera::fillPixelsThread, this, startRow, endRow, _imageWidth, _samplesPerPixel, std::ref(objects), std::ref(pixels)
            , std::ref(_display), mode));
        for (auto& thread : threads) {
            while (threadFinished < numThreads - 1) {
                if (_renderMode == RenderMode::SFML && _display->isOpen()) {
                    _display->clear();
                    _display->display();
                }
            }

            thread.join();
        }
        _pixels.assign(pixels.begin(), pixels.end());
    }

    void Camera::render(ObjectList &objects) {
        if (_renderMode == RenderMode::SFML) {
            this->_pixels.clear();
            fillUint8Array(objects);
            _display->updateTexture(_pixels);
        } else {
            generateImage(objects);
        }
    }

    void Camera::move(Math::Vec3 translation) {
        this->_cameraCenter = this->_cameraCenter + translation;
        this->_lookAt = this->_lookAt + translation;
        this->init();
    }

    void Camera::fillPixelsThread(int startRow, int endRow, int width, int samplesPerPixel, ObjectList &objects,
                                  std::vector<sf::Uint8> &pixels,
                                  std::shared_ptr<SfmlDisplay> &display,
                                  int mode) {
        static Utils::Range<double> range(0.000, 0.999);
        double completionPercentage = 0.0;

        for (int i = startRow; i < endRow; ++i) {
            Camera::totalLinesMutex.lock();
            Camera::totalLinesProcessed++;
            completionPercentage = static_cast<double>(Camera::totalLinesProcessed) / _imageHeight * 100;
            if (mode == 1)
                std::clog << "Completion: " << completionPercentage << "%" << std::endl;
            Camera::totalLinesMutex.unlock();
            for (int j = 0; j < width; ++j) {
                Color pixelColor(0, 0, 0, 255);
                for (int s = 0; s < samplesPerPixel; ++s) {
                    pixelColor += castRay(j, i, objects);
                }
                pixelColor = pixelColor / samplesPerPixel;
                pixels[(i * width + j) * 4] = static_cast<sf::Uint8>(range.clamp(pixelColor.r()) * 256);
                pixels[(i * width + j) * 4 + 1] = static_cast<sf::Uint8>(range.clamp(pixelColor.g()) * 256);
                pixels[(i * width + j) * 4 + 2] = static_cast<sf::Uint8>(range.clamp(pixelColor.b()) * 256);
                pixels[(i * width + j) * 4 + 3] = static_cast<sf::Uint8>(pixelColor.a());
                if (mode != 1)
                    display->updateTexture(pixels);
            }
        }
        Camera::threadFinished++;
    }
}
