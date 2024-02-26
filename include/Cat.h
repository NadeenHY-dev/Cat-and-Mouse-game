#pragma once

#include"MovingObject.h"

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

    //void move(sf::Time deltaTime);

    double distance(sf::Vector2f p1, sf::Vector2f p2);

    void SetDirection(sf::Vector2f);

    virtual void collide(Object&);
    virtual void collide(Mouse&);
    virtual void collide(Cat&);
    virtual void collide(Cheese&);
    virtual void collide(Wall&);
    virtual void collide(Gift&);
    virtual void collide(Door&);
    virtual void collide(Key&);

private:

};

