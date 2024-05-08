/*
** EPITECH PROJECT, 2024
** Parsing (Raytracer)
** File description:
** Parsing systems
*/

#include "Parsing.hpp"

int Parsing::showHelp(bool isFromError) {
    std::cout
            << "USAGE: ./raytracer <SCENE_FILE>"
            << "\n\tSCENE_FILE: scene configuration"
            << std::endl;
    return (isFromError ? 84 : 0);
}

Math::Vector3D Parsing::structToVec3(libconfig::Setting &settings)
{
    double x, y, z;
    settings.lookupValue("x", x);
    settings.lookupValue("y", y);
    settings.lookupValue("z", z);
    return Math::Vector3D(x, y, z);
}

bool Parsing::Parser::processFile() {
    libconfig::Config cfg;

    try {
        cfg.readFile(this->getConfigFilePath());
    } catch (const libconfig::FileIOException &fileException) {
        return false;
    } catch (const libconfig::ParseException &parseException) {
        return false;
    }

    // Parsing of the camera settings
    if (!cfg.exists("camera"))
        return false;
    libconfig::Setting &cameraCfg = cfg.lookup("camera");
    _camCfg.center = Parsing::structToVec3(cameraCfg.lookup("center"));
    cameraCfg.lookupValue("width", this->_camCfg.width);
    cameraCfg.lookupValue("fov", this->_camCfg.fov);
    cameraCfg.lookupValue("samplePerPixel", this->_camCfg.samplePerPixel);

    // Parsing of the spheres
    if (cfg.exists("spheres")) {
        libconfig::Setting &spheresCfg = cfg.lookup("spheres");
        for (int i = 0; i < spheresCfg.getLength(); i++) {
            libconfig::Setting &sphere = spheresCfg[i];
            Parsing::SphereCfg sphereCfg;
            sphereCfg.center = Parsing::structToVec3(sphere.lookup("center"));
            sphere.lookupValue("radius", sphereCfg.radius);
            sphere.lookupValue("material", sphereCfg.materialName);
            _spheresCfg.push_back(sphereCfg);
        }
    }
    return true;
}
