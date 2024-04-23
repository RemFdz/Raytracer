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
    Math::Vec3 viewportU = Math::Vec3(_viewportWidth, 0, 0);
    Math::Vec3 viewportV = Math::Vec3(0, -_viewportHeight, 0);
    Math::Vec3 pixel_delta_u = viewportU / _sceneWidth;
    Math::Vec3 pixel_delta_v = viewportV / _sceneHeight;
    Math::Vec3 viewportUpperLeft = (
        _cameraCenter - Math::Vec3(0, 0, _focalLength) - viewportU/2
        - viewportV/2
    );
    Math::Vec3 pixel00_loc = (
        viewportUpperLeft + pixel_delta_u * x + pixel_delta_v * y
    );
    Math::Vec3 direction = pixel00_loc - _cameraCenter;

    return {_cameraCenter, direction};
}
