#pragma once
#include <SFML/Graphics.hpp>
#include"MovingObject.h"
//#include "Board.h" // Include Board.h for the Board class

class Cat : public MovingObject
{
public:
    Cat(sf::Vector2f v) {
        m_sprite = Icons::instance().getIcon(CAT);
        m_sprite.setPosition(v);
    }

    void SetPosition(sf::Vector2f v) {
        m_sprite.setPosition(v);
    }
    sf::Vector2f getCatPosition();
    //void move(sf::Time deltaTime);

    double distance(sf::Vector2f p1, sf::Vector2f p2);

    void SetDirection(sf::Vector2f);
private:

};

