#pragma once

#include"StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(GIFT);
		m_sprite.setPosition(v);
	}
	~Gift() { ; }


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