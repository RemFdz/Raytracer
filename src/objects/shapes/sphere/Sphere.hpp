/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere shape
*/

#pragma once

#include "../../IObject3D.hpp"
#include "../../../graphics/ray/Ray3D.hpp"

namespace Rtx {
    class Sphere : public Rtx::IObject3D {
    public:
        Sphere(Math::Vec3 center, double radius, const std::shared_ptr<IMaterial> &material) : _center(center), _radius
            (radius) {
            _material = material;
        };

        bool hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) override;

        inline Math::Vec3 getCenter() {
            return _center;
        };

    private:
        Math::Vec3 _center;
        double _radius;
        std::shared_ptr<IMaterial> _material = nullptr;
    };
} // namespace Rtx
