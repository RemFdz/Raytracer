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

typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ZOOM_IN,
    ZOOM_OUT,
    NONE
} KeyPressed_e;

class SfmlDisplay {
    public:
        SfmlDisplay(int width, int height) :
            window(sf::VideoMode(width, height), "Raytracer", sf::Style::Default) {
            window.setVerticalSyncEnabled(true);
            texture = sf::Texture();
            texture.create(width, height);
            sprite = sf::Sprite(texture);
        }

        inline bool isOpen() const { return window.isOpen(); }

        void handleEvents();

        inline void clear(const sf::Color& color = sf::Color::Black) { window.clear(color); }

        inline void updateTexture(std::vector<sf::Uint8> &pixels) {
            texture.update(pixels.data());
            sprite.setTexture(texture, true);
        }

        inline void display() {
            window.draw(sprite);
            window.display();
            _keyPressed = NONE;
        }

        inline KeyPressed_e getKeyPressed() { return _keyPressed;};

    private:
        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite sprite;
        KeyPressed_e _keyPressed = NONE;
};
