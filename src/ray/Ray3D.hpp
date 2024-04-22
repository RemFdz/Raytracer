/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
**
*/

#pragma once

#include "../ray/Ray3D.hpp"
#include "../math/vector3d/Vector3D.hpp"
#include "../math/point3d//Point3D.hpp"

namespace Rtx {
    class Ray3D {
    public:
        Ray3D(Math::Point3D origin, Math::Vector3D direction) : _origin(origin), _direction(direction) {};

        [[nodiscard]] inline Math::Point3D getOrigin() const { return _origin; };
        [[nodiscard]] inline Math::Vector3D getDirection() const {return _direction;};

        inline void setOrigin(Math::Point3D origin) {_origin = origin;};
        inline void setDirection(Math::Vector3D direction) {_direction = direction;};
    private:
        Math::Point3D _origin;
        Math::Vector3D _direction;
    };
}