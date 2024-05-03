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
#include "../../objects/IObject3D.hpp"

namespace Rtx {
    class Scene {
    public:
        Camera _camera;
        explicit Scene(Camera &camera);
        ~Scene() = default;
        void render();

    private:
    };
}