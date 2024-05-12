/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene class
*/

#pragma once
#include <array>
#include "../color/Color.hpp"
#include "../ray/Ray3D.hpp"
#include "../camera/Camera.hpp"
#include "../../objects/IObject3D.hpp"
#include "../../objects/objectlist/ObjectList.hpp"

namespace Rtx {
    /**
    * @brief Scene class
    * @details represents the scene who contains the camera and the objects
    **/
    class Scene {
    public:
        explicit Scene(std::shared_ptr<Camera> &camera);
        ~Scene() = default;

        /**
        * @brief Add an object to the scene
        * @param object The object to add
        **/
        void addObject(const std::shared_ptr<IObject3D> &object);

        /**
        * @brief Render the scene
        **/
        void render();

    private:
        ObjectList _objects = {}; ///< List of objects in the scene
        std::shared_ptr<Camera> _camera; ///< The camera of the scene
    };
} // namespace Rtx