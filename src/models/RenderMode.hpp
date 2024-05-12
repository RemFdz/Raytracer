/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RenderMode enum
*/

#pragma once

namespace Rtx {
    /**
    * @brief RenderMode enum
    * @details Enum for the render mode
    * @var RenderMode::SFML (sfml window)
    * @var RenderMode::IMAGE (image file generation)
    **/
    enum RenderMode {
        SFML,
        IMAGE
    };
} // namespace Rtx