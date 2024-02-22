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

private:

};

