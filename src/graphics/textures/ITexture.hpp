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
    /**
    * @brief Interface for textures
    * @details Interface for textures
    **/
    class ITexture {
    public:
        virtual ~ITexture() = default;

        /**
        * @brief Get the color of a texture
        * @param coords The texture coordinates
        * @param position The position of the hit point
        **/
        [[nodiscard]] virtual Color getColor(TexCoords coords, const Math::Vector3D &position) const = 0;
    private:
    };
}