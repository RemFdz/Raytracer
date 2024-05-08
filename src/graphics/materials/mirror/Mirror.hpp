/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** mirror material
*/

#pragma once
#include "../AMaterial.hpp"

namespace Rtx::Material {
    class Mirror : public AMaterial {
    public:
        explicit Mirror(const Color &color) : AMaterial(color) {};
        ~Mirror() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
    };
}