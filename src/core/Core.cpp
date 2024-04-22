/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#include "Core.hpp"

bool Core::validateArguments(int argc, char **argv) {
    if (argc != 2) {
        return false;
    }
    std::string arg = argv[1];
    if (arg == "-sfml") {
        return true;
    }
    return isValidConfigPath(arg);
}

void Core::run(const std::string& arg) {
    if (arg == "-sfml") {
        WindowDisplay display;
        while (display.isOpen()) {
            display.handleEvents();
            display.clear();
            // Function drawing
            display.display();
        }
    } else {
        std::cout << "Rendering based on configuration from " << arg << std::endl;
    }
}

bool Core::isValidConfigPath(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open())
        return false;
    if (path.size() >= 4 && path.substr(path.size() - 4) == ".cfg")
        return true;
    return false;
}
