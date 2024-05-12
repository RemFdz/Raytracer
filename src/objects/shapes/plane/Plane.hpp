/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Plane
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"

namespace Rtx {

    /**
    * @brief Plane shape
    **/
    class Plane : public IObject3D {
    public:
        Plane(const Math::Point3D& pos, const Math::Vector3D& norm, const std::shared_ptr<IMaterial> &material)
            : position(pos), normal(norm.unitVector()), _material(material) {}

        virtual bool hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) override;

    private:
        Math::Point3D position;
        Math::Vector3D normal;
        std::shared_ptr<IMaterial> _material;
    };

}
