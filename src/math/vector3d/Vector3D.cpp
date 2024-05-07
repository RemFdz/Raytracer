/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#include "Vector3D.hpp"

namespace Math {
    Vector3D Vector3D::randomInHemisphere(const Vector3D &normal) {
        Vector3D inUnitSphere = randomInUnitSphere();

        if (inUnitSphere.dot(normal) > 0.0)
            return inUnitSphere;
        else
            return -inUnitSphere;
    }

    Vector3D Vector3D::randomInUnitSphere() {
        while (true) {
            Vector3D p = random(-1, 1);

            if (p.lengthSquared() >= 1) continue;
            return p;
        }
    }
}
