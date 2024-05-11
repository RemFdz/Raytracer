/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cone
*/

#include "Cone.hpp"

bool Rtx::Cone::hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) {
    const Math::Vector3D& origin = ray.getOrigin();
    const Math::Vector3D& direction = ray.getDirection().unitVector();
    Math::Vector3D apexToOrigin = origin - apex;

    double directionDotAxis = direction.dot(axis);
    Math::Vector3D perpendicular = direction - axis * directionDotAxis;
    Math::Vector3D p = apexToOrigin - axis * apexToOrigin.dot(axis);

    double a = perpendicular.lengthSquared() - sinAngle * sinAngle * directionDotAxis * directionDotAxis;
    double b = 2.0 * (perpendicular.dot(p) - sinAngle * sinAngle * directionDotAxis * apexToOrigin.dot(axis));
    double c = p.lengthSquared() - sinAngle * sinAngle * apexToOrigin.dot(axis) * apexToOrigin.dot(axis);

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }

    double sqrtD = sqrt(discriminant);
    std::array<double, 2> solutions = {(-b - sqrtD) / (2 * a), (-b + sqrtD) / (2 * a)};
    bool hitSomething = false;
    double closest_t = range.getMax();

    for (double t : solutions) {
        if (t >= range.getMin() && t < closest_t) {
            Math::Point3D point = ray.at(t);
            double heightAtHit = (point - apex).dot(axis);
            if (heightAtHit >= 0 && heightAtHit <= height) {
                closest_t = t;
                hitSomething = true;
                hitData.distanceFromOrigin = t;
                hitData.position = point;
                hitData.normal = calculateNormal(point, heightAtHit);
                hitData.material = _material;
                hitData.isFrontFace = ray.getDirection().dot(hitData.normal) < 0;
            }
        }
    }

    return hitSomething;
}
