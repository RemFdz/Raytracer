/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene class
*/

#pragma once
#include <array>
#include "../color/Color.hpp"
#include "../ray/Ray3D.hpp"
#include "../camera/Camera.hpp"
#include "../../objects/shapes/sphere/Sphere.hpp"

namespace Rtx {
    template<int Width, int Height>
    class Scene {
    public:
        explicit Scene(double aspectRatio, Camera camera);

        ~Scene() = default;

        void generateImage();

    private:
        int _width;
        int _height;
        double _aspectRatio = 16 / 9;
        std::array<std::array<Color, Width>, Height> _pixels;
        Camera _camera;
    };
}

#include "Scene.tpp"