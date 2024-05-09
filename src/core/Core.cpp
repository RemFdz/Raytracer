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
    Rtx::RenderMode mode;

    if (!parser.processFile()) {
        std::cerr << "Error: Parsing failed" << std::endl;
        exit(84);
    }

    _renderSfml ? mode = Rtx::RenderMode::SFML : mode = Rtx::RenderMode::IMAGE;

    this->_camera = std::make_shared<Rtx::Camera>(Rtx::Camera(parser.getCamCfg().center,
                                                              parser.getCamCfg().width,
                                                              mode));
    this->_scene = std::make_shared<Rtx::Scene>(Rtx::Scene(_camera));
    this->_display = this->_camera->getDisplay();;

    // TOOD: Need to be generic, this is for testing purposes
    for (auto &sphereCfg : parser.getSpheresCfg()) {
        std::shared_ptr<Rtx::IMaterial> material = Rtx::MaterialFactory::createMaterial(sphereCfg.material.name, sphereCfg.material.color);
        auto sphere = Rtx::ObjectFactory::createObject(
            "sphere",
            sphereCfg.center,
            sphereCfg.radius,
            material);
        _scene->addObject(sphere);
    }

    for (auto &coneCfg : parser.getConesCfg()) {
        std::shared_ptr<Rtx::IMaterial> material = Rtx::MaterialFactory::createMaterial(coneCfg.material.name, coneCfg.material.color);
        auto cone = Rtx::ObjectFactory::createObject(
            "cone",
            coneCfg.apex,
            coneCfg.axis,
            coneCfg.angle,
            coneCfg.height,
            material);
        _scene->addObject(cone);
    }

    for (auto &cylinderCfg : parser.getCylindersCfg()) {
        std::shared_ptr<Rtx::IMaterial> material = Rtx::MaterialFactory::createMaterial(cylinderCfg.materialName, Math::Vec3(0.8, 0.3, 0.3));
        auto cylinder = Rtx::ObjectFactory<Math::Vec3, Math::Vec3, double, double, std::shared_ptr<Rtx::IMaterial>>::createObject(
            "cylinder",
            cylinderCfg.center,
            cylinderCfg.axis,
            cylinderCfg.radius,
            cylinderCfg.height,
            material);
        _scene->addObject(cylinder);
    }

    for (auto &planeCfg : parser.getPlanesCfg()) {
        std::shared_ptr<Rtx::IMaterial> material = Rtx::MaterialFactory::createMaterial(planeCfg.materialName, Math::Vec3(0.8, 0.3, 0.3));
        auto plane = Rtx::ObjectFactory<Math::Vec3, Math::Vec3, std::shared_ptr<Rtx::IMaterial>>::createObject(
            "plane",
            planeCfg.center,
            planeCfg.norm,
            material);
        _scene->addObject(plane);
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
    switch (key) {
        case UP:
            _camera->move(Math::Vec3(0, 0, 1));
            break;
        case DOWN:
            _camera->move(Math::Vec3(0, 0, -1));
            break;
        case LEFT:
            _camera->move(Math::Vec3(-1, 0, 0));
            break;
        case RIGHT:
            _camera->move(Math::Vec3(1, 0, 0));
            break;

        default:
            break;
    }
}
