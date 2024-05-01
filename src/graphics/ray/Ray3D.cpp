/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray3D
*/

#include "Ray3D.hpp"

namespace Rtx {
    Math::Vec3 Ray3D::at(double t) {
        return _origin + _direction * t;
    }

    Color Rtx::Ray3D::color(std::vector<std::shared_ptr<Rtx::IObject3D>> &objects) {
        Math::Vector3D best_normal;
        double best_distance = std::numeric_limits<double>::infinity();
        Color best_color;
        bool hitted = false;
        HitData_t hitData;

        Math::Point3 best_position;

        for (const auto& object : objects) {
            if (object->hit(*this, hitData, 0.001, best_distance)) {
                hitted = true;
                best_distance = hitData.distanceFromOrigin;
                best_position = hitData.position;
                best_normal = Math::Vec3(this->at(hitData.distanceFromOrigin) - object->getCenter()).unitVector();
            }
        }

        if (hitted) {
            Math::Vec3 direction = Color::random_on_hemisphere(best_normal);
            return Ray3D(best_position, direction).color(objects) * 0.5;
        }

        Math::Vector3D unit_direction = _direction.unitVector();
        double t = 0.5 * (unit_direction.y() + 1.0);
        best_color = Math::Vec3(1.0, 1.0, 1.0) * (1.0 - t) + Math::Vec3(0.5, 0.7, 1.0) * t;
        return best_color;
    }



}
