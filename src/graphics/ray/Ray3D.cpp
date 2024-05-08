/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray3D
*/
#include "Ray3D.hpp"
#include "../materials/IMaterial.hpp"

namespace Rtx {
    Math::Vec3 Ray3D::at(double t) {
        return _origin + _direction * t;
    }

    Color Rtx::Ray3D::color(IObject3D &object, Color backgroundColor) {
        Color color;
        Math::Vec3 unit_direction;
        HitData hitData;
        double a = 0;

        if (this->recursionDepthLimit <= 0)
            return {0, 0, 0};

        if (object.hit(*this, hitData, Utils::Range<double>(0.001, infinity))) {
            Ray3D scattered(hitData.position, Math::Vec3(0, 0, 0));
            Color attenuation;
            Color emissionColor = hitData.material->emitted();

            if (hitData.material && hitData.material->scatter(*this, hitData, attenuation, scattered)) {
                this->recursionDepthLimit--;
                scattered.recursionDepthLimit = this->recursionDepthLimit;
                return attenuation * scattered.color(object, backgroundColor);
            }
            return emissionColor;
        }
        return backgroundColor;
    }
}
