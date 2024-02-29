#include"Door.h"
#include"Cat.h"

void Door::collide(Object& obj)
{
	obj.collide(*this);
}

void Door::collide(Mouse&)
{
}

void Door::collide(Cat& cat)
{
	cat.SetDirection({ 0,0 });
}

void Door::collide(Cheese&)
{
}

void Door::collide(Wall&)
{
}

void Door::collide(Gift&)
{
}

void Door::collide(Door&)
{
}

void Door::collide(Key&)
{
}
