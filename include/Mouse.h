#pragma once

#include"MovingObject.h"

class Mouse : public MovingObject
{
public:
	Mouse() { m_sprite = Icons::instance().sprite_mouse(); }
	~Mouse() { ; }

	 void move();
private:

};

