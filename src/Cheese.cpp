#include"Cheese.h"

void Cheese::collide(Object& obj)
{
	obj.collide(*this);
}

void Cheese::collide(Mouse&)
{
}

void Cheese::collide(Cat&)
{
}

void Cheese::collide(Cheese&)
{
}

void Cheese::collide(Wall&)
{
}

void Cheese::collide(Gift&)
{
}

void Cheese::collide(Door&)
{
}

void Cheese::collide(Key&)
{
}
