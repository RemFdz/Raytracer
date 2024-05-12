/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cylinder
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"

namespace Rtx {

    /**
    * @brief Cylinder shape
    **/
    class Cylinder : public IObject3D {
    public:
        Cylinder(const Math::Point3D& baseCenter, const Math::Vector3D& axis, double radius, double height, const std::shared_ptr<IMaterial> &material)
            : baseCenter(baseCenter), axis(axis.unitVector()), radius(radius), height(height), _material(material) {}

        virtual bool hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) override;

    private:
        Math::Point3D baseCenter;
        Math::Vector3D axis;
        double radius;
        double height;
        std::shared_ptr<IMaterial> _material;
    };

}
