/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material abstract interface class
*/

#pragma once

#include "../color/Color.hpp"
#include "../ray/Ray3D.hpp"

namespace Rtx {
    class IMaterial {
    public:
        virtual ~IMaterial() = default;
        virtual bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const = 0;
    };
} // namespace Rtx