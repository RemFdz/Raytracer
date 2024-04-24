/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Represent data of a hit between a ray and an object
*/

#pragma once
#include "../math/vector3d/Vector3D.hpp"

typedef struct HitData_s {
    double distanceFromOrigin = 0.0;
    Math::Vec3 position;
    Math::Vec3 normal;
} HitData_t;