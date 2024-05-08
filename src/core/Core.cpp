/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#include "Core.hpp"

Core::Core(int argc, char **argv) {
    if (!validateArguments(argc, argv)) {
        Parsing::Parser::showHelp(true);
        exit(84);
    }
    init(argv[1]);
}

bool Core::validateArguments(int argc, char **argv) {
    if (argc != 2 && argc != 3) {
        return false;
    }
    if (argc == 3) {
        std::string arg(argv[2]);
        if (arg == "-sfml") {
            _renderSfml = true;
            return true;
        } else {
            return false;
        }
    }
    _path = argv[1];
    return isValidConfigPath(argv[1]);
}

void Core::init(std::string argv) {

    const std::string configPath(argv);
    Parsing::Parser parser(configPath);

    if (!parser.processFile()) {
        std::cerr << "Error: Parsing failed" << std::endl;
        exit(84);
    }
    Rtx::RenderMode mode;

    _renderSfml ? mode = Rtx::RenderMode::SFML : mode = Rtx::RenderMode::IMAGE;

    this->_camera = std::make_shared<Rtx::Camera>(Rtx::Camera(parser.getCamCfg().center,
                                                              parser.getCamCfg().width,
                                                              mode));
    this->_scene = std::make_shared<Rtx::Scene>(Rtx::Scene(_camera));
    this->_display = this->_camera->getDisplay();

    Rtx::Material::Lambertian material(Math::Vec3(0.8, 0.3, 0.3));
    Rtx::Material::Mirror material2(Math::Vec3(0.8, 0.6, 0.2));

    // TOOD: Need to be generic, this is for testing purposes
    for (auto &sphereCfg : parser.getSpheresCfg()) {
        if (sphereCfg.materialName == "lambertian") {
            _scene->addObject(std::make_shared<Rtx::Sphere>(sphereCfg.center, sphereCfg.radius,
                                                           std::make_shared<Rtx::Material::Lambertian>(material)));
        } else if (sphereCfg.materialName == "mirror") {
            _scene->addObject(std::make_shared<Rtx::Sphere>(sphereCfg.center, sphereCfg.radius,
                                                           std::make_shared<Rtx::Material::Mirror>(material2)));
        }
    }
}

void Core::run() {
    _scene->render();
    if (_renderSfml) {
        while (_display->isOpen()) {
            _display->clear();
            _display->handleEvents();
            if (_display->getKeyPressed() != NONE) {
                moveCamera(_display->getKeyPressed());
                _scene->render();
            }
            _display->display();
        }
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

void Core::moveCamera(KeyPressed_e key) {
}
