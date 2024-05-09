/*
** EPITECH PROJECT, 2024
** ParsingModels (Raytracer)
** File description:
** Models of the parsing
*/

#pragma once

#include <string>

#include "../graphics/color/Color.hpp"
#include "../math/vector3d/Vector3D.hpp"

namespace Parsing {
    struct MaterialCfg {
        std::string name;
        Rtx::Color color;
    };

    struct CamCfg {
        int width;
        int samplePerPixel;
        double fov;
        Math::Vector3D center;
    };

    struct SphereCfg {
        Math::Vector3D center;
        double radius;
        MaterialCfg material;
    };

    struct ConeCfg {
        Math::Vector3D apex;
        Math::Vector3D axis;
        double angle;
        double height;
        MaterialCfg material;
    };

    struct CylinderCfg {
        Math::Vector3D center;
        Math::Vector3D axis;
        double radius;
        double height;
        MaterialCfg material;
    };

    struct PlaneCfg {
        Math::Vector3D center;
        Math::Vector3D norm;
        MaterialCfg material;
    };
}
