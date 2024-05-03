/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
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

    void Camera::init() {
        this->_viewportU = Math::Vec3(_viewportWidth, 0, 0);
        this->_viewportV = Math::Vec3(0, -_viewportHeight, 0);
        this->_pixelDeltaU = this->_viewportU / _imageWidth;
        this->_pixelDeltaV = this->_viewportV / _imageHeight;
        this->_viewportUpperLeft = (_cameraCenter - Math::Vec3(0, 0, _focalLength) - this->_viewportU / 2 - this->_viewportV / 2);
        this->_pixel00Loc = this->_viewportUpperLeft + ( this->_pixelDeltaV + this->_pixelDeltaU) * 0.5;
        this->_direction = this->_pixel00Loc - _cameraCenter;
    }

    Color Camera::castRay(int x, int y, ObjectList &objects) {
        Math::Vec3 pixelCenter = this->_pixel00Loc + this->_pixelDeltaU * x + this->_pixelDeltaV * y;
        Math::Vec3 direction = pixelCenter - _cameraCenter;
        Ray3D ray(_cameraCenter, direction);

        return ray.color(objects);
    }

    void Camera::generateImage(ObjectList &objects) {
        Color pixelColor;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);

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

    void Camera::fillUint8Array(ObjectList &objects) {
        Color pixelColor;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);

        for (int j = 0; j < _imageHeight; j++) {
            for (int i = 0; i < _imageWidth; i++) {
                pixelColor = castRay(i, j, objects);
                _pixels.push_back(static_cast<sf::Uint8>(pixelColor.r() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixelColor.g() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixelColor.b() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixelColor.a() * 255.999));
            }
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
