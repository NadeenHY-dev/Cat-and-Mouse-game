#include"Cheese.h"
#include"Mouse.h"

void Cheese::collide(Object& obj)
{
	obj.collide(*this);
}

void Cheese::collide(Mouse& mouse)
{
	/*m_sprite.setPosition({ 1000,1000 });*/
	m_cheeseCounter++;
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
