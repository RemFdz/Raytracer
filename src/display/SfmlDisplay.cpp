/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#include "SfmlDisplay.hpp"

void SfmlDisplay::handleEvents() {
    sf::Event event {};

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right)
                _keyPressed = RIGHT;
            if (event.key.code == sf::Keyboard::Left)
                _keyPressed = LEFT;
            if (event.key.code == sf::Keyboard::Up)
                _keyPressed = UP;
            if (event.key.code == sf::Keyboard::Down)
                _keyPressed = DOWN;
            if (event.key.code == sf::Keyboard::Z)
                _keyPressed = KEY_Z;
            if (event.key.code == sf::Keyboard::S)
                _keyPressed = KEY_S;
            if (event.key.code == sf::Keyboard::Q)
                _keyPressed = KEY_Q;
            if (event.key.code == sf::Keyboard::D)
                _keyPressed = KEY_D;
            if (event.key.code == sf::Keyboard::T)
                _keyPressed = KEY_T;
            if (event.key.code == sf::Keyboard::B)
                _keyPressed = KEY_B;
        }
    }
}
