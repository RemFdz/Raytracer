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

    struct ConeCfg {
        Math::Vector3D apex;
        Math::Vector3D axis;
        double angle;
        double height;
        std::string materialName;
    };

    struct CylinderCfg {
        Math::Vector3D center;
        Math::Vector3D axis;
        double radius;
        double height;
        std::string materialName;
    };

    struct PlaneCfg {
        Math::Vector3D center;
        Math::Vector3D norm;
        std::string materialName;
    };
}
