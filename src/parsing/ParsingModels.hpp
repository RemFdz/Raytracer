/*
** EPITECH PROJECT, 2024
** ParsingModels (Raytracer)
** File description:
** Models of the parsing
*/

#pragma once

#include <string>

#include "../math/vector3d/Vector3D.hpp"

namespace Parsing {
    struct CamCfg {
        int width;
        int samplePerPixel;
        double fov;
        Math::Vector3D center;
    };

    struct SphereCfg {
        Math::Vector3D center;
        std::string materialName;
        double radius;
    };
}
