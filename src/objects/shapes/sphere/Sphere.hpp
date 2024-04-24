/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere shape
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"

class Sphere: public Rtx::IObject3D {
    public:
        Sphere(Math::Vec3 center, double radius) : _center(center), _radius
            (radius) {
            if (radius < 0)
                radius = 0;
        };

        bool hit(const Rtx::Ray3D &ray, HitData_t &hitData, double t_min,
                 double t_max) override;

        inline Math::Vec3 getCenter() override { return _center; };

    private:
        Math::Vec3 _center;
        double _radius;
};
