/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** mirror material
*/

#include "Mirror.hpp"

bool Rtx::Material::Mirror::scatter(const Rtx::Ray3D &ray, const Rtx::HitData &hitData, Rtx::Color &attenuation,
    Rtx::Ray3D &scattered) const {
    Math::Vec3 reflected = ray.getDirection().reflect(hitData.normal);

    scattered = Rtx::Ray3D(hitData.position, reflected);
    attenuation = _albedoColor;
    return true;
}
