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
    int showHelp(bool isFromError);

    Math::Vector3D structToVec3(libconfig::Setting &settings);

    class Parser {
    public:
        Parser(const std::string &filePath) : _configFilePath(filePath) {}
        ~Parser() = default;
        bool processFile(void);

        CamCfg getCamCfg() { return _camCfg; };
        std::list<SphereCfg> getSpheresCfg() { return _spheresCfg; };
        std::string getConfigFilePath() { return _configFilePath; };
    private:
        CamCfg _camCfg = {};
        std::list<SphereCfg> _spheresCfg = {};
        std::string _configFilePath;
    };
}
