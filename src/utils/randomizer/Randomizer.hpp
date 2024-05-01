/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** get random numbers
*/

#pragma once
#include "iostream"
#include "cstdlib"

class Randomizer {
    public:
        static inline double getRandomDouble() { return (double)rand() / RAND_MAX; }
        static inline double getRandomDouble(double min, double max) { return min + (max - min) * getRandomDouble(); }
};