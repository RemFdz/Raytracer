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
#include "graphics/materials/light/Light.hpp"
#include <memory>

#include "parsing/Parsing.hpp"

int main(int argc, char **argv)
{
    Core core(argc, argv);
    core.run();

    /// Put the call for generate and display in the core class after
    //Core core;
    //core.run(argv[1]);
}
