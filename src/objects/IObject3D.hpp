/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** IObject interface
*/

#pragma once

#include "../math/vector3d/Vector3D.hpp"
#include "../models/HitData.hpp"

namespace Rtx {
    class Ray3D;
    class IObject3D {
    public:
        virtual bool hit(const Rtx::Ray3D &ray, HitData_T &hitData, double
        t_min, double t_max)
            = 0;
        virtual inline Math::Vec3 getCenter() = 0;
    private:
    };
}