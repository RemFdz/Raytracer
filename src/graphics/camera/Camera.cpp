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
        this->_pixel_delta_u = this->_viewportU / _imageWidth;
        this->_pixel_delta_v = this->_viewportV / _imageHeight;
        this->_viewportUpperLeft = (_cameraCenter - Math::Vec3(0, 0, _focalLength) - this->_viewportU / 2 - this->_viewportV / 2);
        this->_pixel00_loc = this->_viewportUpperLeft + ( this->_pixel_delta_v + this->_pixel_delta_u) * 0.5;
        this->_direction = this->_pixel00_loc - _cameraCenter;
    }

    Ray3D Camera::castRay(int x, int y) {
        Math::Vec3 pixel_loc = this->_viewportUpperLeft + this->_pixel_delta_u * x + this->_pixel_delta_v * y;
        Math::Vec3 direction = pixel_loc - _cameraCenter;

        return {_cameraCenter, direction};
    }

    void Camera::generateImage() {
        Color pixel_color;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);

        std::cout << "P3\n" << _imageWidth << ' ' << _imageHeight << "\n255\n";
        for (int j = 0; j < _imageHeight; j++) {
            std::clog << "\rScanlines remaining: " << (_imageHeight - j) << ' ' <<
                      std::flush;
            for (int i = 0; i < _imageWidth; i++) {
                Ray3D ray = castRay(i, j);
                pixel_color = ray.color(sphere);
                pixel_color.write_color(std::cout);
            }
        }
        std::clog << "\rDone.\n";
    }

    void Camera::fillUint8Array() {
        Color pixel_color;
        Sphere sphere(Math::Vec3(0, 0, -1), 0.5);

        for (int j = 0; j < _imageHeight; j++) {
            for (int i = 0; i < _imageWidth; i++) {
                Ray3D ray = castRay(i, j);
                pixel_color = ray.color(sphere);
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.r() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.g() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.b() * 255.999));
                _pixels.push_back(static_cast<sf::Uint8>(pixel_color.a() * 255.999));
            }
        }
    }

    void Camera::render() {
        if (_renderMode == RenderMode::SFML) {
            fillUint8Array();
            _display->updateTexture(_pixels);
            while (_display->isOpen()) {
                _display->clear();
                _display->handleEvents();
                _display->display();
            }
        } else {
            generateImage();
        }
    }
}
