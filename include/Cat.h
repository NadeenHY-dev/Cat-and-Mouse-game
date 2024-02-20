#pragma once

#include"MovingObject.h"

class Cat : public MovingObject
{
public:
	Cat() { m_sprite = Icons::instance().sprite_cat(); }
	~Cat() { ; }

private:

};

