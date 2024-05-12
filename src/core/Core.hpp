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

/**
* @brief Core class
* @details Core class used to run the raytracer
**/
class Core {
    public:
        Core(int argc, char **argv);
        ~Core() = default;

        /**
        * @brief Validate the arguments
        * @param argc The number of arguments
        * @param argv The arguments
        **/
        bool validateArguments(int argc, char **argv);

        /**
        * @brief Run the raytracer
        **/
        void run();

        /**
        * @brief Initialize the core
        **/
        void init(std::string argv);

        /**
        * @brief Move the camera depending on the key pressed
        * @param key The key pressed
        **/
        void moveCamera(KeyPressed_e key);

    private:
        /**
        * @brief Check if the path is valid
        * @param path The path to check
        **/
        static bool isValidConfigPath(const std::string &path);

        bool _renderSfml = false; ///< Boolean to know if we render with sfml
        std::string _path; ///< The path of the config file
        std::shared_ptr<Rtx::Camera> _camera; ///< The camera of the scene
        std::shared_ptr<Rtx::Scene> _scene; ///< The scene
        std::shared_ptr<SfmlDisplay> _display; ///< The display
};
