#pragma once

#include"StaticObject.h"

class Door : public StaticObject
{
public:
	Door() { createShape("cat.png"); }
	~Door() { ; }

private:

};

