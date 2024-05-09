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
#include "../../objects/shapes/Cone/Cone.hpp"

namespace Rtx {
    class ObjectFactory {
    public:
        ObjectFactory() = default;
        ~ObjectFactory() = default;
        template <typename... Args>
        static std::shared_ptr<IObject3D> createObject(std::string type, Args... args)
        {
            if (type == "sphere") {
                if constexpr (sizeof...(Args) == 3) {
                    return createSphere(args...);
                } else {
                    throw std::invalid_argument("Invalid number of arguments for sphere creation");
                }
            }
            else if (type == "cone") {
                if constexpr (sizeof...(Args) == 5) {
                    return createCone(args...);
                } else {
                    throw std::invalid_argument("Invalid number of arguments for cone creation");
                }
            }
            else {
                throw std::invalid_argument("Unknown object type");
            }
        };
    private:
        static std::shared_ptr<IObject3D> createSphere(Math::Vec3 center, double radius, const std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Sphere>(center, radius, material);
        };

        static std::shared_ptr<IObject3D> createCone(const Math::Vector3D& apex,
                                                     const Math::Vector3D& axis,
                                                     double angle,
                                                     double height,
                                                     const std::shared_ptr<IMaterial>& material)
        {
            return std::make_shared<Rtx::Cone>(apex, axis, angle, height, material);
        };
    };
}
