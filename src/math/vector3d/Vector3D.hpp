/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

namespace Math {
    class Vector3D {

    public:
        Vector3D() = default;
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};

        [[nodiscard]] inline double getX() const { return _x; }
        [[nodiscard]] inline double getY() const { return _y; }
        [[nodiscard]] inline double getZ() const { return _z; }
        [[nodiscard]] inline double dot(const Vector3D &v) const {return _x * v._x + _y * v._y + _z * v._z;}

        Math::Vector3D operator*(double &k);
        Vector3D scalarProduct(Vector3D const &a, Vector3D const &b);
    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
}
