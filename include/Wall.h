#pragma once

#include"StaticObject.h"


class Wall : public StaticObject
{
public:
	Wall(sf::Vector2f v) {
		m_sprite = Icons::instance().getIcon(WALL);
		m_sprite.setPosition(v); // 
	}
	~Wall() { ; }

private:

};