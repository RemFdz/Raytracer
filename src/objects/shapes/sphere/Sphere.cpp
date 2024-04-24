/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

bool Sphere::hit(const Rtx::Ray3D &ray, HitData_t &hitData, double tMin,
                 double tMax) {
    Math::Vector3D oc = _center - ray.getOrigin();
    double a = ray.getDirection().lengthSquared();
    double half_b = oc.dot(ray.getDirection());
    double c = oc.lengthSquared() - _radius * _radius;
    double discriminant = half_b * half_b - a * c;
    double sqrtd = 0;
    double root = 0;

    if (discriminant < 0)
        return false;

    sqrtd = sqrt(discriminant);
    root = (-half_b - sqrtd) / a;

    if (root <= tMin || tMax <= root) {
        root = (half_b + sqrtd) / a;
        if (root <= tMin || tMax <= root)
            return false;
    }
    hitData.distanceFromOrigin = root;
    hitData.position = ray.at(root);
    hitData.normal = (hitData.position - _center) / _radius;

    return true;
}