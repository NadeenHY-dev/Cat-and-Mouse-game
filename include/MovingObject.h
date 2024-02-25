#pragma once

#include"Object.h"

class MovingObject : public Object 
{
public:
	MovingObject() { ; } // V
	virtual ~MovingObject() { ; } // V
	void setPosition(sf::Vector2f v) {
		m_sprite.setPosition(v);
		m_firstPosition = v;
	}
	//virtual void move() { ; } // V 

	virtual void move(sf::Time deltaTime) {}

protected:
	sf::Vector2f m_direction; // right -> (1,0) ; left->(-1,0) ;
	sf::Vector2f m_firstPosition;
};

