/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#include "Vector3D.hpp"

/*
 * Operators overloading
 */

Math::Vector3D Math::Vector3D::scalarProduct(Math::Vector3D const &a, Math::Vector3D const &b)
{
    return {a.getX() * b.getX(), a.getY() * b.getY(), a.getZ() * b.getZ()};
}

