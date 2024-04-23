/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "math.h"

bool Sphere::hit(const Rtx::Ray3D &ray, float &t) {
    Math::Vector3D oc = Math::Vector3D(
        _center.x() - ray.getOrigin().x(),
        _center.y() - ray.getOrigin().y(),
        _center.z() - ray.getOrigin().z()
    );
    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    } else {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double t0 = (-b - sqrtDiscriminant) / (2 * a);
        double t1 = (-b + sqrtDiscriminant) / (2 * a);

        if (t0 > 0 && t0 < t1) {
            t = t0;
        } else if (t1 > 0) {
            t = t1;
        } else {
            return false;
        }
        return true;
    }
}
