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
#include "../../objects/shapes/plane/Plane.hpp"
#include "../../objects/shapes/Cylinder/Cylinder.hpp"
#include "../../objects/shapes/Cube/Cube.hpp"

namespace Rtx {
    class ObjectFactory {
    public:
        ObjectFactory() = default;
        ~ObjectFactory() = default;
        static inline  std::shared_ptr<IObject3D> createSphere(Math::Vec3 center, double radius, const
        std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Sphere>(center, radius, material);
        };

        static inline std::shared_ptr<IObject3D> createCone(const Math::Vector3D& apex,
                                                     const Math::Vector3D& axis,
                                                     double angle,
                                                     double height,
                                                     const std::shared_ptr<IMaterial>& material)
        {
            return std::make_shared<Rtx::Cone>(apex, axis, angle, height, material);
        };

        static inline std::shared_ptr<IObject3D> createPlane(const Math::Point3D& pos,
                                                      const Math::Vector3D& norm,
                                                      const std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Plane>(pos, norm, material);
        };

        static inline std::shared_ptr<IObject3D> createCube(const Math::Point3D& center,
                                                            double edgeLength,
                                                            const std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Cube>(center, edgeLength, material);
        };

        static inline std::shared_ptr<IObject3D> createCylinder(const Math::Vec3& center,
                                                         const Math::Vec3& axis,
                                                         double radius,
                                                         double height,
                                                         const std::shared_ptr<IMaterial>& material)
        {
            return std::make_shared<Rtx::Cylinder>(center, axis, radius, height, material);
        };
    private:
    };
}
