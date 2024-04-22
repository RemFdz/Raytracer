/*
** EPITECH PROJECT, 2024
** ray_tracer
** File description:
** IObject interface
*/

#include "../ray/Ray3D.hpp"
namespace Rtx {
    class IObject3D {
    public:
        virtual bool hit(const Ray3D &ray, float &t) = 0;
    private:
    };
}