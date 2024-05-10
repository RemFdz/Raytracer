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

namespace Rtx {
    class MaterialFactory {
    public:
        MaterialFactory() = default;
        ~MaterialFactory() = default;
        static std::shared_ptr<IMaterial> createMaterial(std::string type, Color color)
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
            return nullptr;
        };
    };
}
