#pragma once

#include"StaticObject.h"



class Door : public StaticObject
{
public:
	Door() { m_sprite = Icons::instance().sprite_door(); }
	~Door() { ; }

private:

};

