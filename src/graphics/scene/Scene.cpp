/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene class
*/

#include "Scene.hpp"

namespace Rtx {
    Rtx::Scene::Scene(Camera &camera) : _camera(camera) {
    }

    void Scene::render() {
        this->_camera.render(this->_objects);
    }

    void Scene::addObject(const std::shared_ptr<IObject3D> &object) {
        this->_objects.pushBack(object);
    }
}
