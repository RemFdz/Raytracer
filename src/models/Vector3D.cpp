/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#include "models/Vector3D.hpp"

/*
 * Operators overloading
 */
RTX::Math::Vector3D operator+(RTX::Math::Vector3D const &a, RTX::Math::Vector3D const &b)
{
    return {a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()};
}

RTX::Math::Vector3D operator+=(RTX::Math::Vector3D &a, RTX::Math::Vector3D const &b)
{
    a = a + b;
    return a;
}

RTX::Math::Vector3D operator-(RTX::Math::Vector3D const &a, RTX::Math::Vector3D const &b)
{
    return {a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()};
}

RTX::Math::Vector3D operator-=(RTX::Math::Vector3D &a, RTX::Math::Vector3D const &b)
{
    a = a - b;
    return a;
}

RTX::Math::Vector3D operator/(RTX::Math::Vector3D const &a, double const &b)
{
    return {a.getX() / b, a.getY() / b, a.getZ() / b};
}

RTX::Math::Vector3D operator/=(RTX::Math::Vector3D &a, double const &b)
{
    a = a / b;
    return a;
}

RTX::Math::Vector3D operator*(RTX::Math::Vector3D const &a, double const &b)
{
    return {a.getX() * b, a.getY() * b, a.getZ() * b};
}

RTX::Math::Vector3D operator*=(RTX::Math::Vector3D &a, double const &b)
{
    a = a * b;
    return a;
}
