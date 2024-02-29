#pragma once

#include"StaticObject.h"

class Cheese : public StaticObject
{
public:
	Cheese(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(CHEESE);
		m_sprite.setPosition(v);
	}
	~Cheese() { ; }


	virtual void collide(Object&);
	virtual void collide(Mouse&);
	virtual void collide(Cat&);
	virtual void collide(Cheese&);
	virtual void collide(Wall&);
	virtual void collide(Gift&);
	virtual void collide(Door&);
	virtual void collide(Key&);
private:
	int m_cheeseCounter = 0;
};