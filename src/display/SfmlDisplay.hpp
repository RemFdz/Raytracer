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
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../math/vector3d/Vector3D.hpp"

/**
* @brief Enum used to represent the key pressed by the user
* @details Enum used to represent the key pressed by the user
**/
typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ZOOM_IN,
    ZOOM_OUT,
    NONE
} KeyPressed_e;

/**
* @brief Class used to display the rendered image
* @details Class used to display the rendered image
**/
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

        /**
        * @brief Handle the events of the window
        **/
        void handleEvents();

        inline void clear(const sf::Color& color = sf::Color::Black) { window.clear(color); }

        /**
        * @brief Update the texture with the given pixels
        * @param pixels The pixels to update the texture with
        **/
        inline void updateTexture(std::vector<sf::Uint8> &pixels) {
            texture.update(pixels.data());
            sprite.setTexture(texture, true);
        }

        /**
        * @brief Get the mouse position
        * @return Vector3D The mouse position
        **/
        Math::Vec3 getMousePosition() {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            return Math::Vec3(mousePosition.x, mousePosition.y, 0);
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
