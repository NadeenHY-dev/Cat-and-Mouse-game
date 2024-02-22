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

private:

};