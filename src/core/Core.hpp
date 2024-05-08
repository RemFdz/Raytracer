/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "../display/SfmlDisplay.hpp"
#include "../parsing/Parsing.hpp"
#include "../core/Core.hpp"
#include "../graphics/scene/Scene.hpp"
#include "../models/RenderMode.hpp"
#include "../objects/shapes/sphere/Sphere.hpp"
#include "../graphics/materials/lambertian/Lambertian.hpp"
#include "../graphics/materials/mirror/Mirror.hpp"
#include "../graphics/materials/light/Light.hpp"
#include "../factories/object_factory/ObjectFactory.hpp"
#include "../factories/material_factory/MaterialFactory.hpp"

class Core {
    public:
        Core(int argc, char **argv);

        bool validateArguments(int argc, char **argv);

        void run();

        void init(std::string argv);

        void moveCamera(KeyPressed_e key);

    private:
        static bool isValidConfigPath(const std::string &path);
        bool _renderSfml = false;
        std::string _path;
        std::shared_ptr<Rtx::Camera> _camera;
        std::shared_ptr<Rtx::Scene> _scene;
        std::shared_ptr<SfmlDisplay> _display;
};
