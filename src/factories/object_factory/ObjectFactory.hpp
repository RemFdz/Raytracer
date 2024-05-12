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
    /**
    * @brief Object factory
    * @details Factory class for creating objects
    **/
    class ObjectFactory {
    public:
        ObjectFactory() = default;
        ~ObjectFactory() = default;
        static inline  std::shared_ptr<IObject3D> createSphere(Math::Vec3 center, double radius, const
        std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Sphere>(center, radius, material);
        };

        /**
        * @brief Create a cone
        * @param apex The apex of the cone
        * @param axis The axis of the cone
        * @param angle The angle of the cone
        * @param height The height of the cone
        * @param material The material of the cone
        **/
        static inline std::shared_ptr<IObject3D> createCone(const Math::Vector3D& apex,
                                                     const Math::Vector3D& axis,
                                                     double angle,
                                                     double height,
                                                     const std::shared_ptr<IMaterial>& material)
        {
            return std::make_shared<Rtx::Cone>(apex, axis, angle, height, material);
        };

        /**
        * @brief Create a plane
        * @param pos The position of the plane
        * @param norm The normal of the plane
        * @param material The material of the plane
        * @return The plane
        **/
        static inline std::shared_ptr<IObject3D> createPlane(const Math::Point3D& pos,
                                                      const Math::Vector3D& norm,
                                                      const std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Plane>(pos, norm, material);
        };

        /**
        * @brief Create a cube
        * @param center The center of the cube
        * @param edgeLength The edge length of the cube
        * @param material The material of the cube
        * @return The cube
        **/
        static inline std::shared_ptr<IObject3D> createCube(const Math::Point3D& center,
                                                            double edgeLength,
                                                            const std::shared_ptr<IMaterial> &material)
        {
            return std::make_shared<Rtx::Cube>(center, edgeLength, material);
        };

        /**
        * @brief Create a cylinder
        * @param center The center of the cylinder
        * @param axis The axis of the cylinder
        * @param radius The radius of the cylinder
        * @param height The height of the cylinder
        * @param material The material of the cylinder
        * @return The cylinder
        **/
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
