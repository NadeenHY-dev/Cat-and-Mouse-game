#pragma once

#include"StaticObject.h"

class Key : public StaticObject
{
public:
	Key() { createShape("key.png"); }
	~Key() { ; }

private:

};