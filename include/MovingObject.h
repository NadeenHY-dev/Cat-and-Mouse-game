#pragma once

#include"Object.h"

class MovingObject : public Object 
{
public:
	MovingObject() { ; } // V
	~MovingObject() { ; } // V

	virtual void move() { ; } // V 

private:
	sf::Vector2f m_direction; // right -> (1,0) ; left->(-1,0) ;
};

