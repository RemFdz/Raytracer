/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cone
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"
#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"
#include <cmath>
#include <array>
#include <memory>

namespace Rtx {

    /**
    * @brief Cone shape
    **/
    class Cone : public IObject3D {
        public:
            Cone(const Math::Vector3D& apex, const Math::Vector3D& axis, double angle, double height, const std::shared_ptr<IMaterial>& material)
            : apex(apex), axis(axis.unitVector()), angle(angle), height(height), _material(material) {
                sinAngle = std::sin(angle);
                sinAngle *= sinAngle;
            }
            virtual bool hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) override;

        private:
            Math::Point3D apex;
            Math::Vector3D axis;
            double angle;
            double sinAngle; // Stored as sin^2(angle)
            double height;
            std::shared_ptr<IMaterial> _material;

            Math::Vector3D calculateNormal(const Math::Point3D& point, double heightAtHit) const {
                Math::Vector3D radialVector = (point - (apex + axis * heightAtHit)).unitVector();
                return radialVector.cross(axis).cross(radialVector).unitVector();
            }
    };
}

