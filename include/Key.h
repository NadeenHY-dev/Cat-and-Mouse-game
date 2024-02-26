#pragma once

#include"StaticObject.h"

class Key : public StaticObject
{
public:
	Key(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(KEY);
		m_sprite.setPosition(v);
	}
	~Key() { ; }


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