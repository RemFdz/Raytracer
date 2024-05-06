/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** mirror material
*/

#pragma once
#include "../IMaterial.hpp"

namespace Rtx::Material {
    class Mirror : public IMaterial {
    public:
        explicit Mirror(const Color &color) : _albedoColor(color) {};
        ~Mirror() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
    private:
        Color _albedoColor;
    };
}