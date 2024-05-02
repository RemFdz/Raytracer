/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Display class used to render objects in a window using sfml
*/

#include "DIsplay.hpp"

void WindowDisplay::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                _keyPressed = LEFT;
            }
            if (event.key.code == sf::Keyboard::Left) {
                _keyPressed = RIGHT;
            }
            if (event.key.code == sf::Keyboard::Up) {
                _keyPressed = UP;
            }
            if (event.key.code == sf::Keyboard::Down) {
                _keyPressed = DOWN;
            }
        }
    }
}
