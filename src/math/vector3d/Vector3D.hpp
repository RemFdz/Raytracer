/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#pragma once
#include <cmath>
#include "iostream"
#include "../../utils/Randomizer.hpp"

namespace Math {

    class Vector3D {
    public:
        Vector3D() = default;
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};

        [[nodiscard]] inline double x() const { return _x; }
        [[nodiscard]] inline double y() const { return _y; }
        [[nodiscard]] inline double z() const { return _z; }

        inline void operator+=(const Vector3D &v) { _x += v._x; _y += v._y; _z += v._z; };

        [[nodiscard]] inline Vector3D operator-() const { return { -_x, -_y, -_z }; };

        [[nodiscard]] inline Vector3D operator *= (double v) const { return { _x * v, _y * v, _z * v }; };

        [[nodiscard]] inline Vector3D operator/=(const Vector3D &v) const { return {_x / v._x, _y / v._y, _z / v._z}; };

        [[nodiscard]] inline Vector3D operator+(const Vector3D &v) const { return { _x + v._x, _y + v._y, _z + v._z }; }

        [[nodiscard]] inline Vector3D operator-(const Vector3D& v) const { return { _x - v._x, _y - v._y, _z- v._z }; }

        [[nodiscard]] inline Vector3D operator*(const Vector3D& v) const { return { _x * v._x, _y * v._y, _z * v._z }; }

        [[nodiscard]] inline Vector3D operator*(double t) const { return { _x * t, _y * t, _z * t }; }

        [[nodiscard]] inline Vector3D operator/(double t) const { return { _x / t, _y / t, _z / t }; }

        inline bool operator!=(const Vector3D& v) const { return _x != v._x || _y != v._y || _z != v._z; }

        [[nodiscard]] inline double dot(const Vector3D& v) const { return _x * v._x + _y * v._y + _z * v._z; }

        [[nodiscard]] inline Vector3D cross(const Vector3D& v) const {
            return { _y * v._z - _z * v._y, _z * v._x - _x * v._z, _x * v._y - _y * v._x };
        }

        [[nodiscard]] inline double lengthSquared() const
        { return _x * _x + _y * _y + _z * _z; };

        [[nodiscard]] inline double length() const {return sqrt(lengthSquared());};

        [[nodiscard]] inline Vector3D unitVector() const { return *this / this->length(); }

        inline std::ostream &operator<<(std::ostream& out) const { return out << _x << ' ' << _y << ' ' << _z; }

        [[nodiscard]] static inline Vector3D random() {
            return { Utils::Randomizer<double>::getRandom(), Utils::Randomizer<double>::getRandom(), Utils::Randomizer<double>::getRandom() };
        }

        [[nodiscard]] static inline Vector3D random(double min, double max) {
            return { Utils::Randomizer<double>::getRandom(min, max),
                     Utils::Randomizer<double>::getRandom(min, max),
                     Utils::Randomizer<double>::getRandom(min, max) };
        }

        [[nodiscard]] static inline Vector3D randomUnitVector() { return randomInUnitSphere().unitVector(); }


        [[nodiscard]] static Vector3D randomInUnitSphere();

        [[nodiscard]] static Vector3D randomInHemisphere(const Vector3D& normal);

        [[nodiscard]] inline bool nearZero() const {
            const double s = 1e-8;
            return (fabs(_x) < s) && (fabs(_y) < s) && (fabs(_z) < s);
        }

        [[nodiscard]] inline Vector3D reflect(const Vector3D& normal) const {
            return *this - normal * 2 * this->dot(normal);
        }

        //operator[]
        [[nodiscard]] inline double operator[](int i) const {
            if (i == 0) return _x;
            if (i == 1) return _y;
            return _z;
        }

        [[nodiscard]] inline double &operator[](int i) {
            if (i == 0) return _x;
            if (i == 1) return _y;
            return _z;
        }

        Vector3D refract(Vector3D normal, double refractiveIndexRatio);

    protected:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
    using Vec3 = Vector3D;
    using Point3D = Vector3D;
    using Point3 = Vector3D;
} // namespace Math
