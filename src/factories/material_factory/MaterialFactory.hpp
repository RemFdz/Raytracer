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
    class MaterialFactory {
    public:
        MaterialFactory() = default;
        ~MaterialFactory() = default;
        static std::shared_ptr<IMaterial> createMaterial(const std::string& type, Color color, double refractiveIndex
        = 1.0/1.50)
        {
            if (type == "lambertian") {
                return std::make_shared<Rtx::Material::Lambertian>(color);
            }
            if (type == "mirror") {
                return std::make_shared<Rtx::Material::Mirror>(color);
            }
            if (type == "light") {
                return std::make_shared<Rtx::Material::Light>(color);
            }
            if (type == "glass") {
                return std::make_shared<Rtx::Material::Glass>(color, refractiveIndex);
            }
            return nullptr;
        };
    };
}
