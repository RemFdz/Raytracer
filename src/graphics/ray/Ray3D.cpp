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

        for (const auto& object : objects) {
            HitData_t hitData;
            if (object->hit(*this, hitData, 0.001, best_distance)) {
                best_distance = hitData.distanceFromOrigin;
                best_normal = Math::Vec3(this->at(hitData.distanceFromOrigin) - object->getCenter()).unitVector();
                best_color = Color(best_normal.x() + 1, best_normal.y() + 1, best_normal.z() + 1) * 0.5;
            }
        }

        if (best_distance == std::numeric_limits<double>::infinity()) {
            Math::Vector3D unit_direction = _direction.unitVector();
            double t = 0.5 * (unit_direction.y() + 1.0);
            best_color = Math::Vec3(1.0, 1.0, 1.0) * (1.0 - t) + Math::Vec3(0.5, 0.7, 1.0) * t;
        }
        return best_color;
    }

}
