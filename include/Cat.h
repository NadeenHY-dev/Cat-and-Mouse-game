#pragma once

#include"MovingObject.h"

class Cat : public MovingObject
{
public:
	Cat(sf::Vector2f v) {
		m_sprite = Icons::instance().getIcon(CAT);
		m_sprite.setPosition(v);
	}
	~Cat() { ; }

private:

};

