/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane shape
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"

class Plane: public Rtx::IObject3D {
public:
    Plane(Math::Point3D center, Math::Vec3 normal ) : _center(center), _normal(normal) {
    };

    bool hit(const Rtx::Ray3D &ray, HitData_t &hitData, double t_min,
             double t_max) override;

    inline Math::Vec3 getCenter() override { return _center
    ; };

private:
    Math::Point3D _center;
    Math::Vec3 _normal;
};
