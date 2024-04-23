/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color class
*/

#pragma once

#include "../../math/vector3d/Vector3D.hpp"

namespace Rtx {
    class Color : public Math::Vector3D {
    public:
        Color() = default;

        Color(double r, double g, double b) : Math::Vector3D(r, g, b) {
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

        void write_color(std::ostream &out);
    };
}