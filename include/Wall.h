#pragma once

#include"StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall() { m_sprite = Icons::instance().sprite_wall(); }
	~Wall() { ; }

private:

};