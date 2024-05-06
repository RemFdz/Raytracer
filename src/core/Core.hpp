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
#include "../graphics/camera/Camera.hpp"
#include "../graphics/scene/Scene.hpp"
#include "../models/RenderMode.hpp"

class Core {
    public:
        Core(int width)
        : _camera(1, 2, Math::Vec3(0, 0, 1), width, Rtx::RenderMode::SFML),
        _scene(_camera)
        {}

        bool validateArguments(int argc, char **argv);

        void run();

        void init();

        void move_camera(KeyPressed_e key);

    private:
        static bool isValidConfigPath(const std::string &path);

        std::string _path;
        bool _RenderSfml = false;
        Rtx::Camera _camera;
        Rtx::Scene _scene;
};

