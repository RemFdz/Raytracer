/*
** EPITECH PROJECT, 2024
** Parsing (Raytracer)
** File description:
** Parsing systems
*/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <libconfig.h++>
#include <string>
#include <list>

#include "ParsingModels.hpp"

#pragma once

namespace Parsing {
    /**
    * @brief Class to parse the config file
    **/
    class Parser {
    public:
        Parser(const std::string &filePath) : _configFilePath(filePath) {}
        ~Parser() = default;

        /**
        * @brief Process the config file
        * @return true if the file was processed successfully, false otherwise
        **/
        bool processFile(void);

        /**
        * @brief Show the help message
        * @param isFromError true if the help message is shown because of an error, false otherwise
        * @return 84 if the help message is shown because of an error, 0 otherwise
        **/
        static int showHelp(bool isFromError);

        /**
        * @brief Convert a libconfig setting to a Vector3D
        * @param settings the libconfig setting
        * @return the Vector3D
        **/
        static Math::Vector3D structToVec3(libconfig::Setting &settings);

        /**
        * @brief Convert a libconfig setting to a Material cfg struct
        * @param materialSettings the libconfig setting
        * @return the Material cfg
        */
        static MaterialCfg cfgToMaterial(libconfig::Setting &materialSettings);

        /**
        * @brief Convert a libconfig setting to a Color
        * @param colorSettings the libconfig setting
        * @return the Color
        */
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
