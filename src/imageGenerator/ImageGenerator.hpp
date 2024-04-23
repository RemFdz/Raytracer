/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Image Generator
*/

#pragma once

namespace RTX {
    class ImageGenerator {
    public:
        ImageGenerator();
        ~ImageGenerator() = default;

        static void generateImage(int width, int height);
    private:
        int _imageWidth;
        int _imageHeight;
    };
}
