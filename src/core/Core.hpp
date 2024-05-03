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

class Core {
    public:
        Core() {}

        static bool validateArguments(int argc, char **argv);

        void run(const std::string& arg);

    private:
        static bool isValidConfigPath(const std::string &path);
};
