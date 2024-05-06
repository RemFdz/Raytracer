/*
** EPITECH PROJECT, 2024
** Main
** File description:
** Raytracer Main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cstring>

#include "display/SfmlDisplay.hpp"
#include "core/Core.hpp"
#include "graphics/scene/Scene.hpp"
#include "models/RenderMode.hpp"
#include "objects/shapes/sphere/Sphere.hpp"
#include "graphics/materials/lambertian/Lambertian.hpp"
#include "graphics/materials/mirror/Mirror.hpp"
#include <memory>

#include "parsing/Parsing.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return Parsing::showHelp(false);
    if (!strcmp(argv[1], "--help"))
        return Parsing::showHelp(false);

    const std::string configPath(argv[1]);
    Parsing::Parser parser(configPath);

    if (!parser.processFile()) {
        std::cerr << "Error: Parsing failed" << std::endl;
        return 84;
    }

    Rtx::Camera camera(1, 2, parser.getCamCfg().center, parser.getCamCfg().width, Rtx::RenderMode::SFML);
    Rtx::Scene scene(camera);
    Rtx::Material::Lambertian material(Math::Vec3(0.8, 0.3, 0.3));
    Rtx::Material::Mirror material2(Math::Vec3(0.8, 0.6, 0.2));

    // TOOD: Need to be generic, this is for testing purposes
    for (auto &sphereCfg : parser.getSpheresCfg()) {
        if (sphereCfg.materialName == "lambertian") {
            scene.addObject(std::make_shared<Rtx::Sphere>(sphereCfg.center, sphereCfg.radius, std::make_shared<Rtx::Material::Lambertian>(material)));
        } else if (sphereCfg.materialName == "mirror") {
            scene.addObject(std::make_shared<Rtx::Sphere>(sphereCfg.center, sphereCfg.radius, std::make_shared<Rtx::Material::Mirror>(material2)));
        }
    }

    scene.render();

    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
