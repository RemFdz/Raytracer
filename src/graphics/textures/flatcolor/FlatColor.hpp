/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** flat color texture
*/

#pragma once

#include "../ITexture.hpp"

namespace Rtx {
    class FlatColor : public ITexture {
    public:
        explicit FlatColor(const Color &color) : _color(color) {};
        ~FlatColor() override = default;
        [[nodiscard]] Color getColor(TexCoords coords, const Math::Vector3D &position) const override;
    private:
        Color _color;
    };
}