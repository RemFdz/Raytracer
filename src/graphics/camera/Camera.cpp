/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#include "Camera.hpp"

Rtx::Camera::Camera(
    double focalLength,
    double viewportHeight,
    Math::Vec3 cameraCenter,
    int sceneWidth,
    int sceneHeight
) {
    _focalLength = focalLength;
    _viewportHeight = viewportHeight;
    _cameraCenter = cameraCenter;
    _viewportWidth = _viewportHeight * (double(sceneWidth) / sceneHeight);
    _sceneWidth = sceneWidth;
    _sceneHeight = sceneHeight;
}

Rtx::Ray3D Rtx::Camera::castRay(int x, int y) {
    Math::Vec3 offset = getRandomSamplePoint();
    Math::Vec3 viewportU = Math::Vec3(_viewportWidth, 0, 0);
    Math::Vec3 viewportV = Math::Vec3(0, -_viewportHeight, 0);
    Math::Vec3 pixel_delta_u = viewportU / _sceneWidth; // offset to right pixel
    Math::Vec3 pixel_delta_v = viewportV / _sceneHeight; // offset to bottom pixel
    Math::Vec3 viewportUpperLeft = (
        _cameraCenter - Math::Vec3(0, 0, _focalLength) - viewportU / 2
        - viewportV / 2
    );
    Math::Vec3 pixel00_loc = (
        viewportUpperLeft + pixel_delta_u * x + pixel_delta_v * y
    );
    Math::Vec3 pixel_sample = pixel00_loc + (pixel_delta_u * (x + offset.x()))  + ( pixel_delta_v * (y + offset.y()));

    Math::Vec3 direction = pixel_sample - _cameraCenter;

    return {_cameraCenter, direction};
}
