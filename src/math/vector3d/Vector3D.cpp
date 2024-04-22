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
Math::Vector3D operator+(Math::Vector3D const &a, Math::Vector3D const &b)
{
    return {a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()};
}

Math::Vector3D operator+=(Math::Vector3D &a, Math::Vector3D const &b)
{
    a = a + b;
    return a;
}

Math::Vector3D operator-(Math::Vector3D const &a, Math::Vector3D const &b)
{
    return {a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()};
}

Math::Vector3D operator-=(Math::Vector3D &a, Math::Vector3D const &b)
{
    a = a - b;
    return a;
}

Math::Vector3D operator/(Math::Vector3D const &a, double const &b)
{
    return {a.getX() / b, a.getY() / b, a.getZ() / b};
}

Math::Vector3D operator/=(Math::Vector3D &a, double const &b)
{
    a = a / b;
    return a;
}

Math::Vector3D operator*(Math::Vector3D const &a, double const &b)
{
    return {a.getX() * b, a.getY() * b, a.getZ() * b};
}

Math::Vector3D operator*=(Math::Vector3D &a, double const &b)
{
    a = a * b;
    return a;
}

/*
 * Public methods
 */
Math::Vector3D Math::Vector3D::scalarProduct(Math::Vector3D const &a, Math::Vector3D const &b)
{
    return {a.getX() * b.getX(), a.getY() * b.getY(), a.getZ() * b.getZ()};
}
