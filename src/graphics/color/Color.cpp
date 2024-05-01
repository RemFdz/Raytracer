/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** TODO: add description
*/

#include "Color.hpp"
#include "../../utils/range/Range.hpp"

void Rtx::Color::write_color(std::ostream &out) {
    double r = _x;
    double g = _y;
    double b = _z;
    Utils::Range range(0.000, 0.999);
    int rByte = int(255.999 * range.clamp(r));
    int gByte = int(255.999 * range.clamp(g));
    int bByte = int(255.999 * range.clamp(b));

    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}
