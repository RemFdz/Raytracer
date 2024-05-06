/*
** EPITECH PROJECT, 2024
** Main
** File description:
** Raytracer Main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "display/SfmlDisplay.hpp"
#include "core/Core.hpp"
#include "graphics/scene/Scene.hpp"
#include "models/RenderMode.hpp"
#include "objects/shapes/sphere/Sphere.hpp"
#include "graphics/materials/lambertian/Lambertian.hpp"
#include "graphics/materials/mirror/Mirror.hpp"
#include <memory>

int main(int argc, char **argv)
{
    /*
    if (!Core::validateArguments(argc, argv)) {
        std::cerr << "Invalid arguments. Usage: " << argv[0] << " [-sfml | path_to_config.cfg]" << std::endl;
        return 1;
    }*/

    const int width = 800;

    Rtx::Camera camera(1, Math::Vec3(0, 0.1, 0.6), width, Rtx::RenderMode::SFML);
    Rtx::Scene scene(camera);
    Rtx::Material::Lambertian material(Math::Vec3(0.8, 0.3, 0.3));
    Rtx::Material::Mirror material2(Math::Vec3(0.8, 0.6, 0.2));

    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(0, 0, -1), 0.5, std::make_shared<Rtx::Material::Lambertian>(material)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(0, -100.5, -1), 100, std::make_shared<Rtx::Material::Lambertian>(material)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(1, 0, -1), 0.5, std::make_shared<Rtx::Material::Mirror>(material2)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(-1, 0, -1), 0.5, std::make_shared<Rtx::Material::Mirror>(material2)));

    scene.render();
    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
