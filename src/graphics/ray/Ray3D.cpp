/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray3D
*/
#include "Ray3D.hpp"

namespace Rtx {
    Color Rtx::Ray3D::color() {
        Math::Vec3 unit_direction = Math::Vec3(_direction).unitVector();
        auto a = 0.5 * (unit_direction.y() + 1.0);
        Color color = Math::Vec3(1.0, 1.0, 1.0) * (1.0 - a)
                    + Math::Vec3(0.5, 0.7, 1.0) * a;
        
        return color;
    }
}
