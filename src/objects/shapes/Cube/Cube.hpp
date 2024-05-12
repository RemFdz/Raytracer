/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cube
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"

namespace Rtx {

    /**
    * @brief Cube shape
    * **/
    class Cube : public IObject3D {
    public:
        Cube(const Math::Point3D& center, double edgeLength, const std::shared_ptr<IMaterial> &material)
            : center(center), edgeLength(edgeLength), _material(material) {}

        virtual bool hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) override;

    private:
        Math::Point3D center;
        double edgeLength;
        std::shared_ptr<IMaterial> _material;

        bool nearEqual(double a, double b, double epsilon = 1e-10) {
            return std::abs(a - b) < epsilon;
        }
    };

}
