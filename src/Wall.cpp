#include"Wall.h"
#include"Mouse.h"
#include"Cat.h"

void Wall::collide(Object& obj)
{
	obj.collide(*this);
}

void Wall::collide(Mouse& mouse)
{
	mouse.SetDirection({ 0,0 });
}

void Wall::collide(Cat& cat)
{
	cat.SetDirection({ 0,0 });
}

void Wall::collide(Cheese&)
{
	// no thing to do
}

void Wall::collide(Wall&)
{
	// no thing to do
}

void Wall::collide(Gift&)
{
	// no thing to do
}

void Wall::collide(Door&)
{
	// no thing to do
}

void Wall::collide(Key&)
{
	// no thing to do
}
