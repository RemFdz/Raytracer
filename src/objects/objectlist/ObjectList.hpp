/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** object list class
*/

#pragma once
#include "../IObject3D.hpp"
#include <vector>
#include <memory>

namespace Rtx {
    class ObjectList : IObject3D{
    public:
        ObjectList() = default;

        inline void pushBack(const std::shared_ptr<IObject3D> &object) { _objects.push_back(object);}

        bool hit(const Rtx::Ray3D &ray, HitData &hitData, double distanceMin, double distanceMax) override;

    private:
        std::vector<std::shared_ptr<IObject3D>> _objects = {};
    };
}