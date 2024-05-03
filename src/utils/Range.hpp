/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Range class to define interval
*/

#pragma once
#include <algorithm>
#include <limits>
#define infinity std::numeric_limits<double>::infinity()

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

        inline bool contains(T value) { return _min <= value && value <= _max; }
        inline bool surrounds(T value) { return _min < value && value < _max; }

        static const Range empty = Range(infinity, -infinity);
        static const Range universe = Range(-infinity, infinity);
    private:
        T _min;
        T _max;
    };
} // namespace Utils
