/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class WindowDisplay {
    public:
        WindowDisplay() :
            window(sf::VideoMode(width, height), "Raytracer", sf::Style::Default) {
            window.setVerticalSyncEnabled(true);
        }

        inline bool isOpen() const { return window.isOpen(); }

        void handleEvents();

        inline void clear(const sf::Color& color = sf::Color::Black) { window.clear(color); }

        inline void display() { window.display(); }

    private:
        sf::RenderWindow window;
        int width = 1920;
        int height = 1080;
};
