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
    /**
    * @brief Material configuration
    * @details Configuration of a material
    * @param name The name of the material
    * @param color The color of the material
    * @param refractionIndex The refraction index of the material
    **/
    struct MaterialCfg {
        std::string name = "lambertian";
        Rtx::Color color = { 0, 0, 0 };
        double refractionIndex = 1.0;
    };

    /**
    * @brief Camera configuration
    * @details Configuration of a camera
    * @param width The width of the camera
    * @param samplePerPixel The number of samples per pixel
    * @param fov The field of view of the camera
    * @param center The center of the camera
    * @param lookAt The lookAt of the camera
    * @param ambientLightColor The ambient light color of the camera (background)
    **/
    struct CamCfg {
        int width = 800;
        int samplePerPixel = 200;
        double fov = 90.0;
        Math::Vector3D center = { 0.0, 0.0, 0.0 };
        Math::Vector3D lookAt = { 1.0, 1.0, 1.0 };
        Rtx::Color ambientLightColor = { 0.0, 0.0, 0.0 };
    };

    /**
    * @brief Sphere configuration
    * @details Configuration of a sphere
    * @param center The center of the sphere
    * @param radius The radius of the sphere
    * @param material The material of the sphere
    **/
    struct SphereCfg {
        Math::Vector3D center;
        double radius;
        MaterialCfg material;
    };

    /**
    * @brief Cone configuration
    * @details Configuration of a cone
    * @param apex The apex of the cone
    * @param axis The axis of the cone
    * @param angle The angle of the cone
    * @param height The height of the cone
    * @param material The material of the cone
    **/
    struct ConeCfg {
        Math::Vector3D apex;
        Math::Vector3D axis;
        double angle;
        double height;
        MaterialCfg material;
    };

    /**
    * @brief Cube configuration
    * @details Configuration of a cube
    * @param center The center of the cube
    * @param edgeLength The edge length of the cube
    * @param material The material of the cube
    **/
    struct CubeCfg {
        Math::Vector3D center;
        double edgeLength;
        MaterialCfg material;
    };

    /**
    * @brief Cylinder configuration
    *  @details Configuration of a cylinder
    *  @param center The center of the cylinder
    *  @param axis The axis of the cylinder
    *  @param radius The radius of the cylinder
    *  @param height The height of the cylinder
    *  @param material The material of the cylinder
    **/
    struct CylinderCfg {
        Math::Vector3D center;
        Math::Vector3D axis;
        double radius;
        double height;
        MaterialCfg material;
    };

    /**
    * @brief Plane configuration
    * @details Configuration of a plane
    * @param center The center of the plane
    * @param norm The normal of the plane
    * @param material The material of the plane
    **/
    struct PlaneCfg {
        Math::Vector3D center;
        Math::Vector3D norm;
        MaterialCfg material;
    };
}
