/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color class
*/

#include "Color.hpp"
#include "../../utils/Range.hpp"

void Rtx::Color::writeColor(std::ostream &out) {
    double r = _x;
    double g = _y;
    double b = _z;
    static const Utils::Range<double> range(0.000, 0.999);
    int rByte = static_cast<int>(256 * range.clamp(r));
    int gByte = static_cast<int>(256 * range.clamp(g));
    int bByte = static_cast<int>(256 * range.clamp(b));

    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}
