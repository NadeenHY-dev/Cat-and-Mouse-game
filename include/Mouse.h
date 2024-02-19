#pragma once

#include"MovingObject.h"

class Mouse : public MovingObject
{
public:
	Mouse() { createShape("mouse.png"); }
	~Mouse() { ; }

	 void move();
private:

};

