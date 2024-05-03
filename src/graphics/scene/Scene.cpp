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
        this->_camera.render();
    }
}
