/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** TODO: add description
*/

#include "Lambertian.hpp"

bool Rtx::Lambertian::scatter(
    const Rtx::Ray3D &ray,
    const Rtx::HitData &hitData,
    Rtx::Color &attenuation,
    Rtx::Ray3D &scattered
) const {
    Math::Vec3 direction = hitData.normal + Math::Vec3::randomUnitVector();

    if (direction.nearZero()) {
        direction = hitData.normal;
    }
    scattered = Rtx::Ray3D(hitData.position, direction);
    attenuation = _albedo;
    return true;
}
