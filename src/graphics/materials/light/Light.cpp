/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** light material
*/

#include "Light.hpp"

namespace Rtx::Material {
    bool Light::scatter(
        const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const {
        return false;
    }

    Color Light::emitted() const {
        return _albedoColor;
    }
}
