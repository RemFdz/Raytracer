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
    }
}
