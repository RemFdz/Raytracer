/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Range class
*/

#pragma once
#include <algorithm>

namespace Utils {
    template<typename T>
    class Range {
    public:
        Range(T min, T max): _min(min), _max(max) {};
        ~Range() = default;

        inline T clamp(T value) {
            if (value < _min) return _min;
            if (value > _max) return _max;
        }

        inline bool isInRange(T value) { return _min < value < _max; }
    private:
        T _min;
        T _max;
    };
}