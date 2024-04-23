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
}
