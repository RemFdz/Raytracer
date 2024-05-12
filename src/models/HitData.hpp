/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Represent data of a hit between a ray and an object
*/

#pragma once
#include "../math/vector3d/Vector3D.hpp"
#include "TexCoords.hpp"
#include <memory>

namespace Rtx {
    class IMaterial;

    /**
    * @brief HitData model
    * @details Represent data of a hit between a ray and an object
    * @param distanceFromOrigin Distance from the origin of the ray to the hit point
    * @param position Position of the hit point
    * @param normal Normal of the hit point
    * @param material Material of the hit object
    * @param texCoords Texture coordinates of the hit point
    * @param isFrontFace True if the hit point is on the front face of the object
    **/
    struct HitData {
        double distanceFromOrigin = 0.0;
        Math::Vec3 position;
        Math::Vec3 normal;
        std::shared_ptr<IMaterial> material = nullptr;
        TexCoords texCoords;
        bool isFrontFace = true;
    };
} // namespace Rtx