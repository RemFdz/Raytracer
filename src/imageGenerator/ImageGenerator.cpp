/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Image Generator
*/

#include "ImageGenerator.hpp"
#include <iostream>
#include <cmath>
#include "../graphics/color/Color.hpp"

namespace RTX {
    ImageGenerator::ImageGenerator()
    {
        this->_imageWidth = 256;
        this->_imageHeight = 256;
    }

    void ImageGenerator::generateImage(int width, int height)
    {
        Color pixel_color;
        std::cout << "P3\n" << width << ' ' << height << "\n255\n";
        for (int j = 0; j < height; j++) {
            std::clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;
            for (int i = 0; i < width; i++) {
                pixel_color = Color(
                    double(i) / (width-1),
                    double(j) / (height-1),
                    0
                );
                pixel_color.write_color(std::cout);
            }
        }
        std::clog << "\rDone.\n";
    }
}