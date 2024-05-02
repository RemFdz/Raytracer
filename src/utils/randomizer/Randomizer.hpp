/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Randomizer class
*/

#pragma once
#include <cmath>
#include <cstdlib>
#include <iostream>

namespace Utils {
    class Randomizer {
    public:
        static inline double getRandomDouble() {
            return rand() / (RAND_MAX + 1.0);
        }

        static inline double getRandomDouble(double min, double max) {
            return min + (max - min) * getRandomDouble();
        }
    };
}