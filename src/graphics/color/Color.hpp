/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color class
*/

#pragma once

#include "../../math/vector3d/Vector3D.hpp"
#include "SFML/Graphics.hpp"
#include "vector"

namespace Rtx {
    class Color : public Math::Vector3D {
    public:
        Color() = default;

        Color(double r, double g, double b) : Math::Vector3D(r, g, b) {
            _a = 255;
        };

        Color(double r, double g, double b, double a) :
        Math::Vector3D(r, g, b), _a(a) {
        };

        Color(const Math::Vector3D &v) : Math::Vector3D(v) {

        };

        ~Color() = default;

        [[nodiscard]] inline double r() const {
            return x();
        }

        [[nodiscard]] inline double g() const {
            return y();
        }

        [[nodiscard]] inline double b() const {
            return z();
        }

        [[nodiscard]] inline double a() const {
            return _a;
        }

        void write_color(std::ostream &out);

    private:
        double _a = 255;
    };
}