/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material abstract interface class
*/

#pragma once

#include "../color/Color.hpp"
#include "../ray/Ray3D.hpp"

namespace Rtx {
    /**
    * @brief Material abstract interface class
    * @details abstract class for materials
    **/
    class IMaterial {
    public:
        virtual ~IMaterial() = default;

        /**
        * @brief Scatter a ray
        * @details scatter a ray with the material properties and the hit data of the object hitted
        * @param ray The ray to scatter
        * @param hitData The hit data
        * @param attenuation The attenuation
        * @param scattered The scattered ray
        * @return true if the ray is scattered, false otherwise
        **/
        virtual bool scatter(const Ray3D &ray, const HitData &hitData, Color &attenuation, Ray3D &scattered) const = 0;

        /**
        * @brief Get the emitted color of the material
        * @return The emitted color
        **/
        [[nodiscard]] virtual Color emitted() const = 0;
    };
} // namespace Rtx