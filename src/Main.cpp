/*
** EPITECH PROJECT, 2024
** Main
** File description:
** Raytracer Main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "display/DIsplay.hpp"
#include "core/Core.hpp"
#include "graphics/scene/Scene.hpp"

int main(int argc, char **argv)
{
    /*
    if (!Core::validateArguments(argc, argv)) {
        std::cerr << "Invalid arguments. Usage: " << argv[0] << " [-sfml | path_to_config.cfg]" << std::endl;
        return 1;
    }*/

    Rtx::Camera camera(1, 2, Math::Vec3(0, 0, 0), 256, 256);
    Rtx::Scene<256,256> scene(16 / 9, camera);

    if (argc == 1)
        scene.generateImage();
    else {
        WindowDisplay display(256, 256);
        scene.fillSfUint8Pixels();
        std::vector<sf::Uint8> pixels = scene.getPixels();

        display.updateTexture(pixels);
        while (display.isOpen()) {
            display.handleEvents();
            display.clear();
            display.updateTexture(pixels);
            display.display();
        }
    }
    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
