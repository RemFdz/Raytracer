/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace Rtx {
    bool Sphere::hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) {
        Math::Vector3D oc = _center - ray.getOrigin();
        double a = ray.getDirection().lengthSquared();
        double half_b = oc.dot(ray.getDirection());
        double c = oc.lengthSquared() - _radius * _radius;
        double discriminant = half_b * half_b - a * c;
        double sqrtd = 0;
        double root = 0;
        Math::Vector3D outwardNormal;
        bool isFrontFace;

        if (discriminant < 0)
            return false;
        sqrtd = sqrt(discriminant);
        root = (half_b - sqrtd) / a;
        if (!range.surrounds(root)) {
            root = (half_b + sqrtd) / a;
            if (!range.surrounds(root))
                return false;
        }
        outwardNormal = (ray.at(root) - _center) / _radius;
        isFrontFace = ray.getDirection().dot(outwardNormal) < 0;
        hitData.distanceFromOrigin = root;
        hitData.position = ray.at(root);
        hitData.normal = isFrontFace ? outwardNormal : -outwardNormal;
        return true;
    }
}