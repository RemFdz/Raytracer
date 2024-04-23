/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere shape
*/

#pragma once

#include "../../IObject3D.hpp"

class Sphere: public Rtx::IObject3D {
    public:
        Sphere(Math::Vec3 center, double radius) : _center(center), _radius
        (radius) {};
        bool hit(const Rtx::Ray3D &ray, float &t) override;
    private:
        Math::Vec3 _center;
        double _radius;
};
