#include"Wall.h"

void Wall::collide(Object& obj)
{
	obj.collide(*this);
}

void Wall::collide(Mouse&)
{
}

void Wall::collide(Cat&)
{
}

void Wall::collide(Cheese&)
{
}

void Wall::collide(Wall&)
{
}

void Wall::collide(Gift&)
{
}

void Wall::collide(Door&)
{
}

void Wall::collide(Key&)
{
}
