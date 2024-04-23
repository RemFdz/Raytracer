/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** TODO: add description
*/

#include "Color.hpp"

void Rtx::Color::write_color(std::ostream &out) {
    double r = _x;
    double g = _y;
    double b = _z;
    int rByte = int(255.999 * r);
    int gByte = int(255.999 * g);
    int bByte = int(255.999 * b);
    out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}
