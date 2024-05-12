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
    /**
    * @brief Class to generate random numbers
    * @tparam T type of the random number
    * **/
    class Randomizer {
    public:
        /**
        * @brief Generate a random number between 0 and 1
        * @return the random number
        **/
        static inline double getRandom() {
            static std::mt19937 generator(std::random_device{}());
            return std::uniform_real_distribution<T>(0.0, 1.0)(generator);
        }

        /**
        * @brief Generate a random number between min and max
        * @param min the minimum value
        * @param max the maximum value
        * @return the random number
        **/
        static inline double getRandom(T min, T max) { return min + (max - min) * getRandom(); }
    };
}
