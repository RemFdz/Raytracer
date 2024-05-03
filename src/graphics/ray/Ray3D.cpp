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

    Color Rtx::Ray3D::color(IObject3D &object) {
        Color color;
        Math::Vec3 unit_direction;
        HitData hitData;
        double a = 0;

        if (object.hit(*this, hitData, 0, std::numeric_limits<double>::infinity()))
            return (hitData.normal + Math::Vec3(1.0, 1.0, 1.0)) * 0.5;
        unit_direction = Math::Vec3(_direction).unitVector();
        a = 0.5 * (unit_direction.y() + 1.0);
        color = Math::Vec3(1.0, 1.0, 1.0) * (1.0 - a) + Math::Vec3(0.5, 0.7, 1.0) * a;
        return color;
    }
}
