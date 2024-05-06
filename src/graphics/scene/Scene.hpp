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
    class Scene {
        public:
            explicit Scene(Camera &camera);
            ~Scene() = default;
            void addObject(const std::shared_ptr<IObject3D> &object);
            inline std::vector<sf::Uint8> render_sfml() { return this->_camera.render_sfml(this->_objects); };

            inline void render_image() { this->_camera.render_image(this->_objects); };

            inline void edit_postion_camera(double x, double y, double z) {
                _camera.setCameraCenter(x, y, z);
            }

        private:
            ObjectList _objects = {};
            Camera _camera;
    };
} // namespace Rtx
