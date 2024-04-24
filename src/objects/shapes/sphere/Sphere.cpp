/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

double Sphere::hit(const Rtx::Ray3D &ray) {
    Math::Vector3D oc = _center - ray.getOrigin();
    double a = ray.getDirection().dot(ray.getDirection());
    double b = -2.0 * oc.dot(ray.getDirection());
    double c = oc.dot(oc) - _radius * _radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
        return -1.0;
    else
        return (-b - sqrt(discriminant) ) / (2.0 * a);
}
