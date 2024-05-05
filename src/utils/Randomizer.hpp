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
#include <random>

namespace Utils {
    template<typename T>
    class Randomizer {
    public:
        static inline double getRandom() {
            static std::mt19937 generator(std::random_device{}());
            return std::uniform_real_distribution<T>(0.0, 1.0)(generator);
        }
        static inline double getRandom(T min, T max) { return min + (max - min) * getRandom(); }
    };
}
