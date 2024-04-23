/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Image class
*/

#pragma once
#include <array>
#include "../color/Color.hpp"

template <int Width, int Height>
class Image {
    public:
        explicit Image(double aspectRatio);
        ~Image() = default;
        void generateImage();
    private:
        int _width;
        int _height;
        double _aspectRatio = 16 / 9;
        std::array<std::array<Color, Width>, Height> _pixels;
};

template<int Width, int Height>
Image<Width, Height>::Image(double aspectRatio) : _aspectRatio(aspectRatio) {
    _width = Width;
    _height = Width / _aspectRatio;
    if (_height < 1)
        _height = 1;
    for (auto &row : _pixels) {
        row.fill(Color(0, 0, 0));
    }
}

template<int Width, int Height>
void Image<Width, Height>::generateImage()
{
    Color pixel_color;
    std::cout << "P3\n" << _width << ' ' << _height << "\n255\n";
    for (int j = 0; j < _height; j++) {
        std::clog << "\rScanlines remaining: " << (_height - j) << ' ' <<
        std::flush;
        for (int i = 0; i < _width; i++) {
            pixel_color = Color(
                double(i) / (_width-1),
                double(j) / (_height-1),
                0
            );
            _pixels[j][i] = pixel_color;
            pixel_color.write_color(std::cout);
        }
    }
    std::clog << "\rDone.\n";
}
