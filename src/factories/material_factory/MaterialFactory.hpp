/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** material object factory
*/

#pragma once
#include "../../graphics/materials/IMaterial.hpp"
#include "../../graphics/materials/lambertian/Lambertian.hpp"
#include "../../graphics/materials/mirror/Mirror.hpp"
#include "../../graphics/materials/light/Light.hpp"
#include "../../graphics/materials/glass/Glass.hpp"

namespace Rtx {
    /**
    * @brief Material factory
    * @details Factory class to create materials
    **/
    class MaterialFactory {
    public:
        MaterialFactory() = default;
        ~MaterialFactory() = default;

        /**
        * @brief Create a material
        * @param type The type of the material
        * @param color The color of the material
        * @param refractiveIndex The refractive index of the material
        **/
        static std::shared_ptr<IMaterial> createMaterial(const std::string& type, Color color, double refractiveIndex
        = 1.0/1.50);
    };
}
