#pragma once

#include"StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift() { createShape("gift.png"); }
	~Gift() { ; }

private:

};