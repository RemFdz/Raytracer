/*
** EPITECH PROJECT, 2024
** Point3D (Raytracer)
** File description:
** Point 3D Model
*/

namespace Math {
    class Point3D {

    public:
        Point3D() = default;
        Point3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};

        [[nodiscard]] double getX() const { return _x; }
        [[nodiscard]] double getY() const { return _y; }
        [[nodiscard]] double getZ() const { return _z; }

        inline Point3D operator+(const Vector3D& v) const {
            return {_x + v.getX(), _y + v.getY(), _z + v.getZ()};
        }

    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
}
