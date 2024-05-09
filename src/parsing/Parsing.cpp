/*
** EPITECH PROJECT, 2024
** Parsing (Raytracer)
** File description:
** Parsing systems
*/

#include "Parsing.hpp"

int Parsing::Parser::showHelp(bool isFromError) {
    std::cout
            << "USAGE: ./raytracer <SCENE_FILE> ?<-sfml>"
            << "\n\tSCENE_FILE: scene configuration"
            << "\n\t-sfml: optional used the specify that this is SFML renderer"
            << std::endl;
    return (isFromError ? 84 : 0);
}

Math::Vector3D Parsing::Parser::structToVec3(libconfig::Setting &settings)
{
    double x, y, z;

    settings.lookupValue("x", x);
    settings.lookupValue("y", y);
    settings.lookupValue("z", z);
    return {x, y, z};
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
    _camCfg.center = Parsing::Parser::structToVec3(cameraCfg.lookup("center"));
    cameraCfg.lookupValue("width", this->_camCfg.width);
    cameraCfg.lookupValue("fov", this->_camCfg.fov);
    cameraCfg.lookupValue("samplePerPixel", this->_camCfg.samplePerPixel);

    // Parsing of the spheres
    if (cfg.exists("spheres")) {
        libconfig::Setting &spheresCfg = cfg.lookup("spheres");
        for (int i = 0; i < spheresCfg.getLength(); i++) {
            libconfig::Setting &sphere = spheresCfg[i];
            Parsing::SphereCfg sphereCfg;
            sphereCfg.center = Parsing::Parser::structToVec3(sphere.lookup("center"));
            sphere.lookupValue("radius", sphereCfg.radius);
            sphere.lookupValue("material", sphereCfg.materialName);
            _spheresCfg.push_back(sphereCfg);
        }
    }

    // Parsing of the cones
    // Apex (vec3), Axis (vec3), Angle (double), Height (double), MaterialName
    if (cfg.exists("cones")) {
        libconfig::Setting &conesCfg = cfg.lookup("cones");
        for (int i = 0; i < conesCfg.getLength(); i++) {
            libconfig::Setting &cone = conesCfg[i];
            Parsing::ConeCfg coneCfg;
            coneCfg.apex = Parsing::Parser::structToVec3(cone.lookup("apex"));
            coneCfg.axis = Parsing::Parser::structToVec3(cone.lookup("axis"));
            cone.lookupValue("angle", coneCfg.angle);
            cone.lookupValue("height", coneCfg.height);
            cone.lookupValue("material", coneCfg.materialName);
            _conesCfg.push_back(coneCfg);
        }
    }

    // Parsing of the cylinders
    // Center (vec3), Axis (vec3), Radius (double), Height (double), MaterialName
    if (cfg.exists("cylinders")) {
        libconfig::Setting &cylindersCfg = cfg.lookup("cylinders");
        for (int i = 0; i < cylindersCfg.getLength(); i++) {
            libconfig::Setting &cylinder = cylindersCfg[i];
            Parsing::CylinderCfg cylinderCfg;
            cylinderCfg.center = Parsing::Parser::structToVec3(cylinder.lookup("center"));
            cylinderCfg.axis = Parsing::Parser::structToVec3(cylinder.lookup("axis"));
            cylinder.lookupValue("radius", cylinderCfg.radius);
            cylinder.lookupValue("height", cylinderCfg.height);
            cylinder.lookupValue("material", cylinderCfg.materialName);
            _cylindersCfg.push_back(cylinderCfg);
        }
    }

    // Parsing of the planes
    // Center (vec3), Norm (vec3), MaterialName
    if (cfg.exists("planes")) {
        libconfig::Setting &planesCfg = cfg.lookup("planes");
        for (int i = 0; i < planesCfg.getLength(); i++) {
            libconfig::Setting &plane = planesCfg[i];
            Parsing::PlaneCfg planeCfg;
            planeCfg.center = Parsing::Parser::structToVec3(plane.lookup("center"));
            planeCfg.norm = Parsing::Parser::structToVec3(plane.lookup("norm"));
            plane.lookupValue("material", planeCfg.materialName);
            _planesCfg.push_back(planeCfg);
        }
    }

    return true;
}
