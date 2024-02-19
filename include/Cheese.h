#pragma once

#include"StaticObject.h"

class Cheese : public StaticObject
{
public:
	Cheese() { createShape("cheese.png"); }
	~Cheese() { ; }

private:
	
};