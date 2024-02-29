#pragma once

#include"StaticObject.h"



class Door : public StaticObject
{
public:
	Door(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(DOOR);
		m_sprite.setPosition(v);
	}
	~Door() { ; }

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

