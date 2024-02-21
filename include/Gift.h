#pragma once

#include"StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift() { m_sprite = Icons::instance().sprite_gift(); }
	~Gift() { ; }

private:

};