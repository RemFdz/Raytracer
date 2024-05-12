/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Diffuse material using lambertian method for reflection
*/

#pragma once
#include "../AMaterial.hpp"

namespace Rtx::Material {
    /**
     * @brief Lambertian material
     * @details Lambertian material
     */
    class Lambertian : public AMaterial {
    public:
        explicit Lambertian(const Color &color) : AMaterial(color) {};
        ~Lambertian() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
    };
} // namespace Rtx