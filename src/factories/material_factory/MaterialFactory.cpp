/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Material factory
*/

#include "MaterialFactory.hpp"

namespace Rtx {
    std::shared_ptr<IMaterial> MaterialFactory::createMaterial(const std::string &type, Color color, double
    refractiveIndex) {
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
    }
}
