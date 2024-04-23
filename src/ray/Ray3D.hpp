/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
**
*/

#pragma once

#include "../ray/Ray3D.hpp"
#include "../math/vector3d/Vector3D.hpp"

namespace Rtx {
    class Ray3D {
    public:
        Ray3D(Math::Point3 origin, Math::Vec3 direction) : _origin(origin),
        _direction(direction) {};

        [[nodiscard]] inline Math::Vec3 getOrigin() const { return _origin; };
        [[nodiscard]] inline Math::Vec3 getDirection() const {return _direction;};
        inline void setOrigin(Math::Point3 origin) {_origin = origin;};
        inline void setDirection(Math::Vec3 direction) {_direction = direction;};

        [[nodiscard]] inline Math::Point3 at(float t) const {
            return _origin + _direction * t;
        }
    private:
        Math::Point3 _origin;
        Math::Vec3 _direction;
    };
}