/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include "../../utils/Randomizer.hpp"

#include "../../thread/Multi_Thread.hpp"

namespace Rtx {
    Camera::Camera(
        double focalLength,
        double viewportHeight,
        Math::Vec3 cameraCenter,
        int imageWidth,
        RenderMode renderMode
    ) {
        this->_focalLength = focalLength;
        this->_viewportHeight = viewportHeight;
        this->_cameraCenter = cameraCenter;
        this->_imageWidth = imageWidth;
        this->_renderMode = renderMode;

        this->_imageHeight = static_cast<int>(_imageWidth / _aspectRatio);
        this->_viewportWidth = _viewportHeight * (double(_imageWidth) / _imageHeight);

        this->_pixels.clear();
        this->_pixels.reserve(_imageWidth * _imageHeight * 4);

        if (_renderMode == RenderMode::SFML)
            this->_display = std::make_shared<SfmlDisplay>(_imageWidth, _imageHeight);

        this->init();
    }

    //TODO: Refactor by not stocking in the class variables who are only used once
    void Camera::init() {
        this->_viewportU = Math::Vec3(_viewportWidth, 0, 0);
        this->_viewportV = Math::Vec3(0, -_viewportHeight, 0);
        this->_pixelDeltaU = this->_viewportU / _imageWidth;
        this->_pixelDeltaV = this->_viewportV / _imageHeight;
        this->_viewportUpperLeft = (_cameraCenter - Math::Vec3(0, 0, _focalLength) - this->_viewportU / 2 - this->_viewportV / 2);
        this->_pixel00Loc = this->_viewportUpperLeft + ( this->_pixelDeltaV + this->_pixelDeltaU) * 0.5;
    }

    Color Camera::castRay(int x, int y, ObjectList &objects) {
        Math::Vec3 offset = Math::Vec3(Utils::Randomizer<double>::getRandom() - 0.5,Utils::Randomizer<double>::getRandom() - 0.5, 0);
        Math::Vec3 pixelSample = this->_pixel00Loc + this->_pixelDeltaU * (x + offset.x()) + this->_pixelDeltaV * (y
            + offset.y());
        Math::Vec3 direction = pixelSample - _cameraCenter;
        Ray3D ray(_cameraCenter, direction);

        return ray.color(objects);
    }

    void Camera::generateImage(ObjectList &objects) {
        Color pixelColor;

        std::cout << "P3\n" << _imageWidth << ' ' << _imageHeight << "\n255\n";
        for (int j = 0; j < _imageHeight; j++) {
            std::clog << "\rScanlines remaining: " << (_imageHeight - j) << ' ' << std::flush;
            for (int i = 0; i < _imageWidth; i++) {
                pixelColor = castRay(i, j, objects);
                pixelColor.writeColor(std::cout);
            }
        }
        std::clog << "\rDone.\n";
    }

   void Camera::fillUint8Array(ObjectList& objects) {
        int num_threads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(num_threads);
        int total_pixels = _imageWidth * _imageHeight * 4;
        _pixels.resize(total_pixels);

        auto render_segment = [&](int index, int start, int end) {
            Utils::Range<double> local_range(0.000, 0.999);
            int pixel_index = start * _imageWidth * 4;

            for (int i = start; i < end; i++) {
                for (int j = 0; j < _imageWidth; j++) {
                    Color pixelColor(0, 0, 0, 255);
                    for (int s = 0; s < _samplesPerPixel; s++) {
                        pixelColor += castRay(j, i, objects);
                    }
                    pixelColor = pixelColor / _samplesPerPixel;
                    _pixels[pixel_index++] = static_cast<sf::Uint8>(local_range.clamp(pixelColor.r()) * 256);
                    _pixels[pixel_index++] = static_cast<sf::Uint8>(local_range.clamp(pixelColor.g()) * 256);
                    _pixels[pixel_index++] = static_cast<sf::Uint8>(local_range.clamp(pixelColor.b()) * 256);
                    _pixels[pixel_index++] = static_cast<sf::Uint8>(pixelColor.a() * 255.99);
                }
            }
        };

        int segment_height = _imageHeight / num_threads;
        for (int i = 0; i < num_threads; ++i) {
            int start = i * segment_height;
            int end = (i == num_threads - 1) ? _imageHeight : (start + segment_height);
            threads[i] = std::thread(render_segment, i, start, end);
        }

        for (auto &thread : threads) {
            thread.join();
        }
    }


    void Camera::render(ObjectList &objects) {
        if (_renderMode == RenderMode::SFML) {
            fillUint8Array(objects);
            _display->updateTexture(_pixels);
            while (_display->isOpen()) {
                _display->clear();
                _display->handleEvents();
                _display->display();
            }
        } else {
            generateImage(objects);
        }
    }
}
