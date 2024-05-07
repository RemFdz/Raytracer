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
    Core core(800);

    if (!core.validateArguments(argc, argv)) {
        std::cerr << "Invalid arguments. Usage: " << argv[0] << " [-sfml | path_to_config.cfg]" << std::endl;
        return 1;
    }
    core.init();
    core.run();
}
