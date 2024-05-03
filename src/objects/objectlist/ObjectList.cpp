/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** ObjectList
*/

#include "ObjectList.hpp"

namespace Rtx {
    bool Rtx::ObjectList::hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) {
        double closestObj = range.getMax();
        bool hitted = false;

        for (const auto& object : this->_objects) {
            if (object->hit(ray, hitData, range)) {
                hitted = true;
                closestObj = hitData.distanceFromOrigin;
                range.setMax(closestObj);
            }
        }
        return hitted;
    }
}
