#include"Gift.h"

void Gift::collide(Object& obj)
{
	obj.collide(*this);
}

void Gift::collide(Mouse&)
{
}

void Gift::collide(Cat&)
{
}

void Gift::collide(Cheese&)
{
}

void Gift::collide(Wall&)
{
}

void Gift::collide(Gift&)
{
}

void Gift::collide(Door&)
{
}

void Gift::collide(Key&)
{
}
