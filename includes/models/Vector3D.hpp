/*
** EPITECH PROJECT, 2024
** Vector3D (Raytracer)
** File description:
** Vector3D Model
*/

namespace RTX::Math {
    class Vector3D {

    public:
        Vector3D() = default;
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {};
    private:
        double _x = 0;
        double _y = 0;
        double _z = 0;
    };
}
