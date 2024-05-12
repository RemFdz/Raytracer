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
    /**
    * @brief Interface for 3D objects
    **/
    class IObject3D {
    public:
        IObject3D() = default;
        virtual ~IObject3D() = default;

        /**
        * @brief Check if a ray hits the object
        **/
        virtual bool hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) = 0;
    private:
    };
}