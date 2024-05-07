/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#include "Core.hpp"
#include "../graphics/scene/Scene.hpp"
#include "../graphics/materials/IMaterial.hpp"
#include "../graphics/materials/lambertian/Lambertian.hpp"
#include "../graphics/materials/mirror/Mirror.hpp"

bool Core::validateArguments(int argc, char **argv) {
    if (argc != 2 && argc != 3) {
        return false;
    }
    std::string arg(argv[2]);
    if (argc == 3) {
        if (arg == "-sfml") {
            _RenderSfml = true;
            return true;
        }
    }
    _path = argv[1];
    return true;
    return isValidConfigPath(argv[1]);
}

void Core::init() {
    Rtx::Scene scene(_camera);
    Rtx::Material::Lambertian material(Math::Vec3(0.8, 0.3, 0.3));
    Rtx::Material::Mirror material2(Math::Vec3(0.8, 0.6, 0.2));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(0, 0, -1), 0.5, std::make_shared<Rtx::Material::Lambertian>(material)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(0, -100.5, -1), 100, std::make_shared<Rtx::Material::Lambertian>(material)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(1, 0, -1), 0.5, std::make_shared<Rtx::Material::Mirror>(material2)));
    scene.addObject(std::make_shared<Rtx::Sphere>(Math::Vec3(-1, 0, -1), 0.5, std::make_shared<Rtx::Material::Mirror>(material2)));
}

void Core::run() {
    if (_RenderSfml == true) {
        SfmlDisplay _display(800, 600);
        std::vector<sf::Uint8> pixels = _scene.render_sfml();
        _display.updateTexture(pixels);
        while (_display.isOpen()) {
            _display.clear();
            _display.handleEvents();
            if (_display.getKeyPressed() != NONE) {
                move_camera(_display.getKeyPressed());
                pixels = _scene.render_sfml();
                _display.updateTexture(pixels);
            }
            _display.display();
        }
    } else {
        _scene.render_image();
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

void Core::move_camera(KeyPressed_e key) {
    if (key == KEY_Z)
        _scene.edit_postion_camera(0, 0, 1);
    if (key == KEY_S)
        _scene.edit_postion_camera(0, 0, -1);
    if (key == KEY_Q)
        _scene.edit_postion_camera(1, 0, 0);
    if (key == KEY_D)
        _scene.edit_postion_camera(-1, 0, 0);
    if (key == KEY_T)
        _scene.edit_postion_camera(0, 1, 0);
    if (key == KEY_B)
        _scene.edit_postion_camera(0, -1, 0);
};
