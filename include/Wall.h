#pragma once

#include"StaticObject.h"


class Wall : public StaticObject
{
public:
    Wall() { ; }
	Wall(sf::Vector2f v) {
		m_sprite = Icons::instance().getIcon(WALL);
		m_sprite.setPosition(v); // 
	}
	~Wall() { ; }


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