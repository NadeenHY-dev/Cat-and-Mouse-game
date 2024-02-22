#pragma once

#include"StaticObject.h"

class Road : public StaticObject
{
public:
	Road(sf::Vector2f v) {
		m_sprite = Icons::instance().getIcon(ROAD);
		m_sprite.setPosition(v);
	}
	~Road() { ; }

private:

};