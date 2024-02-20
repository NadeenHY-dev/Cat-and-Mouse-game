#pragma once

#include"StaticObject.h"

class Cheese : public StaticObject
{
public:
	Cheese() { m_sprite = Icons::instance().sprite_cheese(); }
	~Cheese() { ; }

private:
	
};