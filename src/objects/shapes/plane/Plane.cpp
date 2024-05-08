/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Plane
*/

#include "Plane.hpp"

bool Rtx::Plane::hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) {
    double denominator = normal.dot(ray.getDirection());

    if (std::fabs(denominator) > 1e-6) {
        double t = (position - ray.getOrigin()).dot(normal) / denominator;
        if (t >= range.getMin() && t <= range.getMax()) {
            hitData.distanceFromOrigin = t;
            hitData.position = ray.at(t);
            hitData.normal = normal;
            hitData.material = _material;
            return true;
        }
    }
    return false;
}
