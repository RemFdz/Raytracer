/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Diffuse material using lambertian method for reflection
*/

#pragma once
#include "../IMaterial.hpp"

namespace Rtx::Material {
    class Lambertian : public IMaterial {
    public:
        explicit Lambertian(const Color &color) : _albedoColor(color) {};
        ~Lambertian() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;

    private:
        Color _albedoColor;
    };
} // namespace Rtx