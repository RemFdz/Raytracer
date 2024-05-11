/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** glass material (refraction)
*/

#include "Glass.hpp"

bool Rtx::Material::Glass::scatter(const Rtx::Ray3D &ray, const Rtx::HitData &hitData, Rtx::Color &attenuation,
                                   Rtx::Ray3D &scattered) const {
    attenuation = _albedoColor;
    Math::Vector3D direction;
    double refractionRatio = hitData.isFrontFace ? (1.0 / this->_refractionIndex) : this->_refractionIndex;
    Math::Vector3D unitDirection = ray.getDirection().unitVector();

    // Recalcul de la direction du rayon par rapport à la normale de la surface de collision
    Math::Vector3D recalculatedDirection = unitDirection - hitData.normal * (2.0 * unitDirection.dot(hitData.normal));

    double cosTheta = fmin(hitData.normal.dot(-unitDirection), 1.0);
    double sinTheta = sqrt(1.0 - cosTheta * cosTheta);
    bool canRefract = refractionRatio * sinTheta <= 1.0;

    if (canRefract || schlick(cosTheta, refractionRatio) > Utils::Randomizer<double>::getRandom())
        direction = recalculatedDirection.refract(hitData.normal, refractionRatio);
    else
        direction = recalculatedDirection.reflect(hitData.normal);

    scattered = Rtx::Ray3D(hitData.position, direction);
    return true;
}

double Rtx::Material::Glass::schlick(double cosine, double refractionIndex) const {
    double r0 = (1 - refractionIndex) / (1 + refractionIndex);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}
