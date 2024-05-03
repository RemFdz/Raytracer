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

        inline T getMin() const { return _min; }
        inline T getMax() const { return _max; }

        inline void setMin(T min) { _min = min; }
        inline void setMax(T max) { _max = max; }

        static Range empty() { return Range(-infinity, infinity); }
        static Range universe() { return Range(-infinity, infinity); }
    private:
        T _min;
        T _max;
    };
} // namespace Utils
