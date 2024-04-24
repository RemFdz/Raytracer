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
        Camera _camera;
        explicit Scene(double aspectRatio, Camera camera);

        ~Scene() = default;

        void generateImage();

        void fillSfUint8Pixels();

        inline std::vector<sf::Uint8> &getPixels() { return _pixels; }

    private:
        int _width;
        int _height;
        double _aspectRatio = 16 / 9;
        std::vector<sf::Uint8> _pixels;
    };
}

#include "Scene.tpp"