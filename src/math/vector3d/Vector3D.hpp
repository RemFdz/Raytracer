/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#pragma once
#include <cmath>
#include <random>
#include <iostream>

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

        [[nodiscard]] inline Vector3D unitVector() const {
            return *this / this->length();
        }

        [[nodiscard]] inline double lengthSquared() const
        {return _x * _x + _y * _y + _z * _z;};

        [[nodiscard]] inline double length() const {return sqrt(lengthSquared());};

        inline std::ostream &operator<<(std::ostream& out) {
            return out << _x << ' ' << _y << ' ' << _z;
        }

        [[nodiscard]] inline Vector3D unit_vector() const {return *this / length();}


        static Vector3D random_unit_vector() {
            static std::mt19937 gen(std::random_device{}());
            static std::uniform_real_distribution<> dist(-1.0, 1.0);
            Vector3D v;
            do {
                v = Vector3D{dist(gen), dist(gen), dist(gen)};
            } while (v.lengthSquared() >= 1.0);  // Ensure it's inside the unit sphere
            return v.unitVector();  // Normalize it
        }

        void applyGammaCorrection(double gamma) {
            double power = 1.0 / gamma;
            _x = std::pow(_x, power);
            _y = std::pow(_y, power);
            _z = std::pow(_z, power);
        }

    protected:
            double _x = 0;
            double _y = 0;
            double _z = 0;
    };

    // Make sure dot is a static member function if it's used as such
    static double dot(const Vector3D& a, const Vector3D& b) {
        return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
    }

    static Vector3D random_on_hemisphere(const Vector3D& normal) {
        auto in_unit_sphere = Vector3D::random_unit_vector();
        if (dot(in_unit_sphere, normal) > 0.0) {
            return in_unit_sphere;
        } else {
            return -in_unit_sphere;
        }
    }

    using Vec3 = Vector3D;
    using Point3D = Vector3D;
    using Point3 = Vector3D;
}
