/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

#include <cmath>
#include "iostream"

namespace Math {

    class Vector3D {
        using Vec3 = Vector3D;
        using Point3D = Vector3D;
        using Point3 = Vector3D;
    public:
        Vector3D() = default;
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};

        [[nodiscard]] inline double x() const { return _x; }
        [[nodiscard]] inline double y() const { return _y; }
        [[nodiscard]] inline double z() const { return _z; }
        [[nodiscard]] inline double dot(const Vector3D &v) const {return _x * v._x + _y * v._y + _z * v._z;}

        inline Vector3D operator*(double &v) const
            {return {_x * v, _y * v, _z * v};};

        inline Vector3D operator-() const {return {-_x, -_y, -_z};};

        inline Vector3D operator+=(Vector3D const &v) const
            {return {_x + v._x, _y + v._y, _z + v._z};};

        inline Vector3D operator *= (double const &v) const
            {return {_x * v, _y * v, _z * v};};

        inline Vector3D operator/=(Vector3D const &v) const
            {return {_x / v._x, _y / v._y, _z / v._z};};

        inline Vector3D operator+(const Vector3D & v) const {
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

        inline Vector3D operator/(double t) {
            return {_x / t, _y / t, _z / t};
        }

        inline double dot(const Vector3D& v) {
            return _x * v._x + _y * v._y + _z * v._z;
        }

        inline Vector3D cross(const Vector3D& v) {
            return {_y * v._z - _z * v._y,
                    _z * v._x - _x * v._z,
                    _x * v._y - _x * v._z};
        }

        inline Vector3D unitVector() {
            return *this / this->length();
        }

        inline double lengthSquared() const
        {return _x * _x + _y * _y + _z * _z;};

        inline double length() const {return sqrt(lengthSquared());};


        Vector3D scalarProduct(Vector3D const &a, Vector3D const &b);

        inline std::ostream &operator<<(std::ostream& out) {
            return out << _x << ' ' << _y << ' ' << _z;
        }

    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
}
