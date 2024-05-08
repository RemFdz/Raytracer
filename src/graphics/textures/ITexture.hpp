/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** interface for textures
*/

#pragma once
#include "../color/Color.hpp"
#include "../../models/TexCoords.hpp"
#include "../../math/vector3d/Vector3D.hpp"

namespace Rtx {
    class ITexture {
    public:
        virtual ~ITexture() = default;
        [[nodiscard]] virtual Color getColor(TexCoords coords, const Math::Vector3D &position) const = 0;
    private:
    };
}