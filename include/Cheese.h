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

private:
	
};