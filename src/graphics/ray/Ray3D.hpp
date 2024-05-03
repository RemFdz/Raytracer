/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
**
*/

#pragma once

#include "../../math/vector3d/Vector3D.hpp"
#include "../../objects/IObject3D.hpp"
#include "../color/Color.hpp"

namespace Rtx {
    class Ray3D {
    public:
        Ray3D(Math::Point3 origin, Math::Vec3 direction) : _origin(origin),
        _direction(direction) {};

        [[nodiscard]] inline const Math::Vec3 &getOrigin() const { return
        _origin;};
        [[nodiscard]] inline const Math::Vec3 &getDirection() const {return
        _direction;};

        [[nodiscard]] inline Math::Point3 at(double t) const {
            return _origin + _direction * t;
        }

        Math::Vec3 at(double t);

        Color color(IObject3D &object);
    private:
        Math::Point3 _origin;
        Math::Vec3 _direction;
    };
} // namespace Rtx