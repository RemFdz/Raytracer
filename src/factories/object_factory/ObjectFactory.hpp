/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** object factory
*/

#pragma once
#include <memory>
#include "../../objects/IObject3D.hpp"
#include "../../graphics/color/Color.hpp"
#include "../../objects/shapes/sphere/Sphere.hpp"

namespace Rtx {
    template <typename... Args>
    class ObjectFactory {
    public:
        ObjectFactory() = default;
        ~ObjectFactory() = default;
        static std::shared_ptr<IObject3D> createObject(std::string type, Args... args)
        {
            if (type == "sphere") {
                return std::make_shared<Rtx::Sphere>(args...);
            }
            return nullptr;
        };
    private:
    };
}
