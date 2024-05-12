/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** abstract default implementation for materials
*/

#pragma once

#include "IMaterial.hpp"

namespace Rtx::Material {
    /**
    * @brief Abstract default implementation for materials
    * @details Abstract class for materials
    **/
    class AMaterial : public IMaterial {
    public:
        explicit AMaterial(const Color &color) : _albedoColor(color) {};
        ~AMaterial() override = default;
        [[nodiscard]]Color emitted() const override { return {0, 0, 0}; };
    protected:
        Color _albedoColor; ///< The albedo color of the material
    };
}