/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#include "Vector3D.hpp"

namespace Math {
    Vector3D Vector3D::randomInUnitSphere() {
        while (true) {
            Vector3D p = random(-1, 1);

            if (p.lengthSquared() >= 1) continue;
            return p;
        }
    }

    Vector3D Vector3D::refract(Vector3D normal, double refractiveIndexRatio) {
        Vector3D uv = *this;
        double cosTheta = fmin(-uv.dot(normal), 1.0);
        Vector3D rOutPerp = (uv + normal * cosTheta) * refractiveIndexRatio;
        Vector3D rOutParallel = normal * -sqrt(fabs(1.0 - rOutPerp.lengthSquared()));

        return rOutPerp + rOutParallel;
    }
}
