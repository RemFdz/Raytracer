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

int main(int argc, char **argv)
{
    /*
    if (!Core::validateArguments(argc, argv)) {
        std::cerr << "Invalid arguments. Usage: " << argv[0] << " [-sfml | path_to_config.cfg]" << std::endl;
        return 1;
    }*/

    const int width = 800;

    Rtx::Camera camera(1, 2, Math::Vec3(0, 0, 0), width, Rtx::RenderMode::SFML);
    Rtx::Scene scene(camera);

    scene.render();
    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
