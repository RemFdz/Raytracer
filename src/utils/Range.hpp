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
    /**
    * @brief Class to define an range interval
    * @tparam T type of the interval
    * @details
    * This class is used to define an interval between two values
    * It can be used to check if a value is in the interval, or to clamp a value to the interval
    **/
    template<typename T>
    class Range {
    public:
        Range(T min, T max): _min(min), _max(max) {};
        ~Range() = default;

        /**
        * @brief Clamp a value to the interval
        * @param value the value to clamp
        * @return the clamped value
        **/
        inline T clamp(T value) const {
            if (value < _min) return _min;
            if (value > _max) return _max;
            return value;
        }

        /**
        * @brief Check if a value is in the interval or equal interval limits
        * @param value the value to check
        * @return true if the value is in the interval, false otherwise
        **/
        inline bool contains(T value) { return _min <= value && value <= _max; }

        /**
        * @brief Check if a value is strictly in the interval
        * @param value the value to check
        * @return true if the value is strictly in the interval, false otherwise
        **/
        inline bool surrounds(T value) { return _min < value && value < _max; }

        inline T getMin() const { return _min; }
        inline T getMax() const { return _max; }

        inline void setMin(T min) { _min = min; }
        inline void setMax(T max) { _max = max; }
    private:
        T _min;
        T _max;
    };
} // namespace Utils
