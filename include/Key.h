#pragma once

#include"StaticObject.h"

class Key : public StaticObject
{
public:
	Key() { m_sprite = Icons::instance().sprite_key(); }
	~Key() { ; }

private:

};