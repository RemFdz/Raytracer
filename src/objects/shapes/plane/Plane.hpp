/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Plane implementation
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"
#include "../../../math/vector3d/Vector3D.hpp"

namespace Rtx {

    class Plane : public IObject3D {
    public:
        // Ajout du paramètre pour le vecteur normal et initialisation dans le constructeur
        Plane(const Math::Point3D& pos, const Math::Vector3D& norm, const std::shared_ptr<IMaterial> &material)
            : position(pos), normal(norm.unitVector()), _material(material) {}

        virtual bool hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) override {
            double denominator = normal.dot(ray.getDirection());

            if (std::fabs(denominator) > 1e-6) {  // Check not parallel
                double t = (position - ray.getOrigin()).dot(normal) / denominator;
                if (t >= range.getMin() && t <= range.getMax()) {
                    hitData.distanceFromOrigin = t;
                    hitData.position = ray.at(t);
                    hitData.normal = normal;
                    hitData.material = _material; // Assume material is a field in HitData
                    return true;
                }
            }
            return false;
        }

    private:
        Math::Point3D position;
        Math::Vector3D normal; // Vecteur normal défini et initialisé
        std::shared_ptr<IMaterial> _material;  // Placeholder for material class
    };

} // namespace Rtx
