/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** glass material (refraction)
*/

#pragma once
#include "../AMaterial.hpp"

namespace Rtx::Material {
    /**
     * @brief Glass material
     * @details Glass material
     */
    class Glass : public AMaterial {
    public:
        explicit Glass(const Color &color, double refractionIndex) : AMaterial(color), _refractionIndex(refractionIndex){};
        ~Glass() override = default;
        bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const override;
    private:
        double _refractionIndex;

        /**
        * @brief Schlick approximation
        * @details Schlick approximation used to calculate the reflectance of the material
        * @param cosine The cosine
        * @param refractionIndex The refraction index
        * @return The schlick approximation
        **/
        double schlick(double cosine, double refractionIndex) const;
    };
}
