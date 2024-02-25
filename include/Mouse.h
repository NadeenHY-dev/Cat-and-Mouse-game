#pragma once

#include"MovingObject.h"

class Mouse : public MovingObject
{
public:
	Mouse(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(MOUSE);
		m_sprite.setPosition(v);
	}
	~Mouse() { ; }

	void setDirection(sf::Keyboard::Key key);

	sf::Vector2f getMousePosition();
private:

};

