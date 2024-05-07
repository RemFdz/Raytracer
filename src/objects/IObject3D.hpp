/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** IObject interface
*/

#pragma once

#include "../math/vector3d/Vector3D.hpp"
#include "../models/HitData.hpp"
#include "../utils/Range.hpp"

namespace Rtx {
    class Ray3D;
    class IObject3D {
    public:
        IObject3D() = default;
        virtual ~IObject3D() = default;
        virtual bool hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) = 0;
    private:
    };
}
