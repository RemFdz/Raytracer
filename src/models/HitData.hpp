/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Represent data of a hit between a ray and an object
*/

#pragma once
#include "../math/vector3d/Vector3D.hpp"
#include <memory>

namespace Rtx {
    class IMaterial;

    struct HitData {
        double distanceFromOrigin = 0.0;
        Math::Vec3 position;
        Math::Vec3 normal;
        std::shared_ptr<IMaterial> material = nullptr;
    };
} // namespace Rtx
