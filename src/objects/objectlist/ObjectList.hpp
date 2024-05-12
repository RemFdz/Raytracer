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
    /**
    * @brief Object list class
    * @details This class is used to store multiple objects in a list
    * and check if a ray hits any of them
    **/
    class ObjectList : public IObject3D {
    public:
        ObjectList() = default;

        /**
        * @brief Add an object to the list
        **/
        inline void pushBack(const std::shared_ptr<IObject3D> &object) { _objects.push_back(object);}

        bool hit(const Rtx::Ray3D &ray, HitData &hitData, Utils::Range<double> range) override;

    private:
        std::vector<std::shared_ptr<IObject3D>> _objects = {}; ///< List of objects
    };
} // namespace Rtx