#include"Key.h"

void Key::collide(Object& obj)
{
	obj.collide(*this);
}

void Key::collide(Mouse&)
{
}

void Key::collide(Cat& obj)
{
}

void Key::collide(Cheese&)
{
}

void Key::collide(Wall&)
{
}

void Key::collide(Gift&)
{
}

void Key::collide(Door&)
{
}

void Key::collide(Key&)
{
}
