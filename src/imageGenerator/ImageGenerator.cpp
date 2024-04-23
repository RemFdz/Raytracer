/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Image Generator
*/

#include "ImageGenerator.hpp"
#include <iostream>

namespace RTX {
    ImageGenerator::ImageGenerator()
    {
        this->_imageWidth = 256;
        this->_imageHeight = 256;
    }

    void ImageGenerator::generateImage(int width, int height)
    {
        std::cout << "P3\n" << width << ' ' << height << "\n255\n";
        for (int j = 0; j < height; j++) {
            std::clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;
            for (int i = 0; i < width; i++) {
                auto r = double(i) / (width - 1);
                auto g = double(j) / (height - 1);
                auto b = 0.0;
                int ir = int(255.999 * r);
                int ig = int(255.999 * g);
                int ib = int(255.999 * b);

                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }
        std::clog << "\rDone.                 \n";
    }
}