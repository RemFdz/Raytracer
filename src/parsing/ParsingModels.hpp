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
        std::string name = "lambertian";
        Rtx::Color color = { 0, 0, 0 };
    };

    struct CamCfg {
        int width = 800;
        int samplePerPixel = 200;
        double fov = 90.0;
        Math::Vector3D center = { 0.0, 0.0, 0.0 };
        Math::Vector3D lookAt = { 1.0, 1.0, 1.0 };
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

    struct CubeCfg {
        Math::Vector3D center;
        double edgeLength;
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
