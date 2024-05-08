/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** abstract default implementation for materials
*/

#pragma once

#include "IMaterial.hpp"

namespace Rtx::Material {
    class AMaterial : public IMaterial {
    public:
        explicit AMaterial(const Color &color) : _albedoColor(color) {};
        ~AMaterial() override = default;
        [[nodiscard]]Color emitted() const override { return {0, 0, 0}; };
    protected:
        Color _albedoColor;
    };
}