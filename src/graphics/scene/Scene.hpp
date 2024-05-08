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
#include "../../objects/objectlist/ObjectList.hpp"

namespace Rtx {
    class Scene {
    public:
        explicit Scene(std::shared_ptr<Camera> &camera);
        ~Scene() = default;
        void addObject(const std::shared_ptr<IObject3D> &object);
        void render();

    private:
        ObjectList _objects = {};
        std::shared_ptr<Camera> _camera;
    };
} // namespace Rtx