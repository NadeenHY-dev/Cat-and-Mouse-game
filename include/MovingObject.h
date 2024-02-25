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



	void move(sf::Time deltaTime) {
		const auto speedPerSecond = 20.f;
		m_sprite.move(m_direction * speedPerSecond * deltaTime.asSeconds());
	}

protected:
	sf::Vector2f m_direction; // right -> (1,0) ; left->(-1,0) ;
	sf::Vector2f m_firstPosition;
};

