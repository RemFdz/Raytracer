/*
** EPITECH PROJECT, 2024
** Parsing (Raytracer)
** File description:
** Parsing systems
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <libconfig.h++>
#include <string>
#include <list>

#include "ParsingModels.hpp"

#pragma once

namespace Parsing {
    class Parser {
    public:
        Parser(const std::string &filePath) : _configFilePath(filePath) {}
        ~Parser() = default;
        bool processFile(void);
        static int showHelp(bool isFromError);

        static Math::Vector3D structToVec3(libconfig::Setting &settings);
        static MaterialCfg cfgToMaterial(libconfig::Setting &materialSettings);
        static Rtx::Color cfgToColor(libconfig::Setting &colorSettings);

        CamCfg getCamCfg() { return _camCfg; };
        std::list<SphereCfg> getSpheresCfg() { return _spheresCfg; };
        std::list<ConeCfg> getConesCfg() { return _conesCfg; };
        std::list<CylinderCfg> getCylindersCfg() { return _cylindersCfg; };
        std::list<PlaneCfg> getPlanesCfg() { return _planesCfg; };
        std::list<CubeCfg> getCubesCfg() { return _cubesCfg; };
        std::string getConfigFilePath() { return _configFilePath; };
    private:
        CamCfg _camCfg = {};
        std::list<SphereCfg> _spheresCfg = {};
        std::list<ConeCfg> _conesCfg = {};
        std::list<CylinderCfg> _cylindersCfg = {};
        std::list<PlaneCfg> _planesCfg = {};
        std::list<CubeCfg> _cubesCfg = {};
        std::string _configFilePath;
    };
}
