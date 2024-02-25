#pragma once

#include"MovingObject.h"

class Cat : public MovingObject
{
public:
    explicit Cat(sf::Vector2f v) {
        m_sprite = Icons::instance().getIcon(CAT);
        m_sprite.setPosition(v);
    }
    virtual ~Cat() {}

    // Make this method virtual so it can be overridden
    virtual void move(sf::Time deltaTime) /*override*/ {
        // Basic movement logic (can be empty if only subclasses move)
    }
private:

};

