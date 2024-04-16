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

        [[nodiscard]] double getX() const { return _x; }
        [[nodiscard]] double getY() const { return _y; }
        [[nodiscard]] double getZ() const { return _z; }

        Vector3D scalarProduct(Vector3D const &a, Vector3D const &b);
    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
}
