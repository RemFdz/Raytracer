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
#include "memory"

namespace Rtx {;
    class Camera {
    public:
        Color backgroundColor = Color(0.1, 0.1, 0.1);

        Camera(
            Math::Vec3 cameraCenter,
            int imageWidth,
            RenderMode renderMode
        );

        void init();

        Color castRay(int x, int y, ObjectList &objets);

        void generateImage(ObjectList &objects);

        void fillUint8Array(ObjectList &objects);

        void render(ObjectList &objects);

        void inline setAspectRatio(double aspectRatio) { _aspectRatio = aspectRatio; }

        void inline setSamplesPerPixel(int samplesPerPixel) { _samplesPerPixel = samplesPerPixel; }

        void inline setFov(double fov) { this->fov = fov; }

    private:
        double _aspectRatio = 16.0 / 9.0;
        int _samplesPerPixel = 1000;

        double fov = 90;
        double _viewportHeight;
        double _viewportWidth;
        Math::Vec3 _cameraCenter;
        int _imageWidth = 0;
        int _imageHeight = 0;

        RenderMode _renderMode;
        std::vector<sf::Uint8> _pixels;
        std::shared_ptr<SfmlDisplay> _display;

        Math::Vec3 _viewportU;
        Math::Vec3 _viewportV;
        Math::Vec3 _pixelDeltaU;
        Math::Vec3 _pixelDeltaV;
        Math::Vec3 _viewportUpperLeft;
        Math::Vec3 _pixel00Loc;

        Math::Vec3 _lookAt = Math::Vec3(0, 0, -1);
        Math::Vec3 _upVector = Math::Vec3(0, 1, 0);

    };
} // namespace Rtx