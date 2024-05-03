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
#include "memory"

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

        Ray3D castRay(int x, int y);

        inline void move(Math::Vec3 direction) {
            _cameraCenter += direction;};
        inline Math::Vec3 &getCenter() { return _cameraCenter; };

        void generateImage();

        void fillUint8Array();

        void render();

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

        Math::Vec3 _viewportU;
        Math::Vec3 _viewportV;
        Math::Vec3 _pixel_delta_u;
        Math::Vec3 _pixel_delta_v;
        Math::Vec3 _viewportUpperLeft;
        Math::Vec3 _pixel00_loc;
        Math::Vec3 _direction;
    };
}