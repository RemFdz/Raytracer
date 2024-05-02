/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#pragma once
#include <cmath>
#include "iostream"

namespace Math {

    class Vector3D {
    public:
        Vector3D() = default;
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};

        [[nodiscard]] inline double x() const { return _x; }
        [[nodiscard]] inline double y() const { return _y; }
        [[nodiscard]] inline double z() const { return _z; }

        inline Vector3D operator-() const {return {-_x, -_y, -_z};};

        inline void operator+=(const Vector3D &v)
            {_x += v._x; _y += v._y; _z += v._z;};

        inline Vector3D operator *= (double const &v) const
            {return {_x * v, _y * v, _z * v};};

        inline Vector3D operator/=(const Vector3D &v) const
            {return {_x / v._x, _y / v._y, _z / v._z};};

        inline Vector3D operator+(const Vector3D &v) const {
            return {_x + v._x, _y + v._y, _z + v._z};
        }

        inline Vector3D operator-(const Vector3D& v) const {
            return {_x - v._x, _y - v._y, _z- v._z};
        }

        inline Vector3D operator*(const Vector3D& v) const {
            return {_x * v._x, _y * v._y, _z * v._z};
        }

        inline Vector3D operator*(double t) const {
            return {_x * t, _y * t, _z * t};
        }

        inline Vector3D operator/(double t) const {
            return {_x / t, _y / t, _z / t};
        }

        [[nodiscard]] inline double dot(const Vector3D& v) const {
            return _x * v._x + _y * v._y + _z * v._z;
        }

        [[nodiscard]] inline Vector3D cross(const Vector3D& v) const {
            return {_y * v._z - _z * v._y,
                    _z * v._x - _x * v._z,
                    _x * v._y - _x * v._z};
        }

        [[nodiscard]] inline double lengthSquared() const
        {return _x * _x + _y * _y + _z * _z;};

        [[nodiscard]] inline double length() const {return sqrt(lengthSquared());};

        [[nodiscard]] inline Vector3D unitVector() const {
            return *this / this->length();
        }

        inline std::ostream &operator<<(std::ostream& out) {
            return out << _x << ' ' << _y << ' ' << _z;
        }

        [[nodiscard]] inline Vector3D unit_vector() const {return *this / length();}
    protected:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
    using Vec3 = Vector3D;
    using Point3D = Vector3D;
    using Point3 = Vector3D;
}
