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
        Sphere(Math::Point3D center, double radius) : _center(center), _radius(radius) {};
        bool hit(const Rtx::Ray3D &ray, float &t) override;
    private:
        Math::Point3D _center;
        double _radius;
};
