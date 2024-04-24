/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** IObject interface
*/

#include "../graphics/ray/Ray3D.hpp"

namespace Rtx {
    class IObject3D {
    public:
        virtual double hit(const Ray3D &ray) = 0;
    private:
    };
}