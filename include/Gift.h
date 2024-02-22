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

private:

};