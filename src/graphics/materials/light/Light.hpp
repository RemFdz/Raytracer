/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** light material
*/

#pragma once

#include "../AMaterial.hpp"

namespace Rtx::Material {
    class Light : public AMaterial {
    public:
        explicit Light(const Color &color) : AMaterial(color) {};
        ~Light() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
        [[nodiscard]] Color emitted() const override;
    };
} // namespace Rtx::Material