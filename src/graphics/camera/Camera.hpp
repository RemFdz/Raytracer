/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#pragma once
#include "../../math/vector3d/Vector3D.hpp"

namespace Rtx {
    class Camera {
    public:

        Camera(
            double focalLength,
            double viewportHeight,
            Math::Vec3 cameraCenter,
            int sceneWidth,
            int sceneHeight
        );

    private:
        double _focalLength;
        double _viewportHeight;
        double _viewportWidth;
        Math::Vec3 _cameraCenter;
    };
}