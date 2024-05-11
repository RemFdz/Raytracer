/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** Cube
*/

#include "Cube.hpp"

bool Rtx::Cube::hit(const Ray3D& ray, HitData& hitData, Utils::Range<double> range) {
    Math::Vector3D boundsMin = center - Math::Vector3D(edgeLength / 2.0, edgeLength / 2.0, edgeLength / 2.0);
    Math::Vector3D boundsMax = center + Math::Vector3D(edgeLength / 2.0, edgeLength / 2.0, edgeLength / 2.0);
    double t_min = range.getMin();
    double t_max = range.getMax();

    // Test intersection with all 3 slabs
    for (int i = 0; i < 3; ++i) {
        double invD = 1.0 / ray.getDirection()[i];
        double t0 = (boundsMin[i] - ray.getOrigin()[i]) * invD;
        double t1 = (boundsMax[i] - ray.getOrigin()[i]) * invD;

        if (invD < 0) std::swap(t0, t1);
        t_min = t0 > t_min ? t0 : t_min;
        t_max = t1 < t_max ? t1 : t_max;

        if (t_max <= t_min)
            return false;
    }

    hitData.distanceFromOrigin = t_min;
    Math::Point3D hitPoint = ray.at(t_min);
    hitData.position = hitPoint;

    // Determine which slab was hit
    Math::Vector3D normal;
    for (int i = 0; i < 3; i++) {
        if (std::abs(hitPoint[i] - boundsMin[i]) < 0.0001) {
            normal[i] = -1;
        } else if (std::abs(hitPoint[i] - boundsMax[i]) < 0.0001) {
            normal[i] = 1;
        } else {
            normal[i] = 0;
        }
    }

    hitData.normal = normal;
    hitData.material = _material;
    return true;
}
