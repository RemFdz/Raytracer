/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** glass material (refraction)
*/

#pragma once
#include "../AMaterial.hpp"

namespace Rtx::Material {
    class Glass : public AMaterial {
    public:
        explicit Glass(const Color &color, double refractionIndex) : AMaterial(color), _refractionIndex(refractionIndex){};
        ~Glass() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
    private:
        double _refractionIndex;

        double schlick(double cosine, double refractionIndex) const;
    };
}
