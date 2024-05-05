/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera
*/

#pragma once

#include "../../math/vector3d/Vector3D.hpp"
#include "../ray/Ray3D.hpp"
#include "../../objects/shapes/sphere/Sphere.hpp"
#include "../../models/RenderMode.hpp"
#include "../../display/SfmlDisplay.hpp"
#include "../../objects/objectlist/ObjectList.hpp"
#include "../../utils/Range.hpp"

#include "memory"
#include <mutex>
#include <thread>
#include <cmath>
#include <vector>

namespace Rtx {

    class Camera {
    public:
        Camera(
            double focalLength,
            double viewportHeight,
            Math::Vec3 cameraCenter,
            int imageWidth,
            RenderMode renderMode
        );

        void init();

        Color castRay(int x, int y, ObjectList &objets);

        void generateImage(ObjectList &objects);

        void fillUint8Array(ObjectList &objects);

        void render(ObjectList &objects);

    private:
        double _focalLength;
        double _viewportHeight;
        double _viewportWidth;
        Math::Vec3 _cameraCenter;
        int _imageWidth = 0;
        int _imageHeight = 0;
        double _aspectRatio = 16 / 9;
        RenderMode _renderMode;
        std::vector<sf::Uint8> _pixels;
        std::shared_ptr<SfmlDisplay> _display;
        int _samplesPerPixel = 10;

        Math::Vec3 _viewportU;
        Math::Vec3 _viewportV;
        Math::Vec3 _pixelDeltaU;
        Math::Vec3 _pixelDeltaV;
        Math::Vec3 _viewportUpperLeft;
        Math::Vec3 _pixel00Loc;

    };
} // namespace Rtx