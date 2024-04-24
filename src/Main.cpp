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

    const int width = 800;
    const int height = 600;

    Rtx::Camera camera(1, 2, Math::Vec3(0, 0, 0), width, height);
    Rtx::Scene<width,height> scene(16 / 9, camera);

    if (argc == 1)
        scene.generateImage();
    else {
        WindowDisplay display(width, height);
        scene.fillSfUint8Pixels();
        std::vector<sf::Uint8> pixels = scene.getPixels();
        display.updateTexture(pixels);
        while (display.isOpen()) {
            display.clear();
            display.handleEvents();
            if (display.getKeyPressed() != NONE) {
                if (display.getKeyPressed() == LEFT)
                    scene._camera.move(Math::Vec3(0.05, 0, 0));
                if (display.getKeyPressed() == RIGHT)
                    scene._camera.move(Math::Vec3(-0.05, 0, 0));
                if (display.getKeyPressed() == UP)
                    scene._camera.move(Math::Vec3(0, 0, -0.05));
                if (display.getKeyPressed() == DOWN)
                    scene._camera.move(Math::Vec3(0, 0, 0.05));
                scene.fillSfUint8Pixels();
                pixels = scene.getPixels();
                display.updateTexture(pixels);
            }
            display.display();
        }
    }
    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
