#pragma once

#include"MovingObject.h"

class Cat : public MovingObject
{
public:
	Cat() { createShape("cat.png"); }
	~Cat() { ; }

private:

};

