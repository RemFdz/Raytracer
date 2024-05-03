/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ObjectList
*/

#include "ObjectList.hpp"

namespace Rtx {
    bool Rtx::ObjectList::hit(const Rtx::Ray3D &ray, HitData &hitData, double distanceMin, double distanceMax) {
        double closestObj = distanceMax;
        bool hitted = false;

        for (const auto& object : this->_objects) {
            if (object->hit(ray, hitData, distanceMin, closestObj)) {
                hitted = true;
                closestObj = hitData.distanceFromOrigin;
            }
        }
        return hitted;
    }
}
