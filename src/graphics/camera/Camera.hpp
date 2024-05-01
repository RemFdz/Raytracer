/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#pragma once
#include "../../math/vector3d/Vector3D.hpp"
#include "../ray/Ray3D.hpp"
#include "../../utils/randomizer/Randomizer.hpp"

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
        double _focalLength = 0; // distance between the camera and the viewport
        double _viewportHeight = 0; // height of the viewport
        double _viewportWidth = 0; // width of the viewport
        Math::Vec3 _cameraCenter; // center of the camera
        int _sceneWidth = 0; // width of the scene
        int _sceneHeight = 0; // height of the scene

        [[nodiscard]] inline Math::Vec3 getRandomSamplePoint() const {
            return { Utils::Randomizer::randomDouble() - 0.5, Utils::Randomizer::randomDouble() - 0.5, 0 };
        }
    };
}