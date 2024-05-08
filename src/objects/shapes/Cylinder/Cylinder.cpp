/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

bool Rtx::Cylinder::hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) {
    Math::Vector3D oc = ray.getOrigin() - baseCenter;
    Math::Vector3D direction = ray.getDirection() - axis * ray.getDirection().dot(axis);
    Math::Vector3D perpendicular = oc - axis * oc.dot(axis);

    double a = direction.lengthSquared();
    double b = 2.0 * direction.dot(perpendicular);
    double c = perpendicular.lengthSquared() - radius * radius;

    double discriminant = b * b - 4 * a * c;
    bool hitSomething = false;
    double closest_t = range.getMax();

    if (discriminant >= 0) {
        double sqrtD = sqrt(discriminant);
        double t0 = (-b - sqrtD) / (2 * a);
        double t1 = (-b + sqrtD) / (2 * a);

        for (double t : {t0, t1}) {
            if (t >= range.getMin() && t < closest_t) {
                Math::Point3D point = ray.at(t);
                double heightAtHit = (point - baseCenter).dot(axis);
                if (heightAtHit >= 0 && heightAtHit <= height) {
                    closest_t = t;
                    hitSomething = true;
                    hitData.distanceFromOrigin = t;
                    hitData.position = point;
                    hitData.normal = (point - (baseCenter + axis * heightAtHit)).unitVector();
                    hitData.material = _material;
                }
            }
        }
    }

    if (ray.getDirection().dot(axis) != 0) {
        for (double h : {0.0, height}) {
            double tPlane = ((baseCenter + axis * h) - ray.getOrigin()).dot(axis) / ray.getDirection().dot(axis);
            if (tPlane >= range.getMin() && tPlane < closest_t) {
                Math::Point3D point = ray.at(tPlane);
                if ((point - (baseCenter + axis * h)).lengthSquared() <= radius * radius) {
                    closest_t = tPlane;
                    hitSomething = true;
                    hitData.distanceFromOrigin = tPlane;
                    hitData.position = point;
                    hitData.normal = axis * (h == 0.0 ? -1 : 1);
                    hitData.material = _material;
                }
            }
        }
    }

    return hitSomething;
}
