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
#include "imageGenerator/ImageGenerator.hpp"

int main(int argc, char **argv)
{
    if (!Core::validateArguments(argc, argv)) {
        std::cerr << "Invalid arguments. Usage: " << argv[0] << " [-sfml | path_to_config.cfg]" << std::endl;
        return 1;
    }
    RTX::ImageGenerator::generateImage(256, 256);
    //Core core;
    //core.run(argv[1]);
}
