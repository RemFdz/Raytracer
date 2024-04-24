/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#pragma once
#include "../../math/vector3d/Vector3D.hpp"
#include "../ray/Ray3D.hpp"

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

        Ray3D castRay(int x, int y);

        inline void move(Math::Vec3 direction) {
            _cameraCenter += direction;};
        inline Math::Vec3 &getCenter() { return _cameraCenter; };
    private:
        double _focalLength;
        double _viewportHeight;
        double _viewportWidth;
        Math::Vec3 _cameraCenter;
        int _sceneWidth = 0;
        int _sceneHeight = 0;
    };
}