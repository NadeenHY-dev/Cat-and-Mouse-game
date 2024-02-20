#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    Object(sf::Texture& texture) : m_sprite(texture) {}
    virtual ~Object() {}

    virtual void render(sf::RenderWindow& window) {
        window.draw(m_sprite);
    }

protected:
    sf::Sprite m_sprite;
};
