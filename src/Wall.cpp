#include"Wall.h"
#include"Mouse.h"
void Wall::collide(Object& obj)
{
	obj.collide(*this);
}

void Wall::collide(Mouse& mouse)
{
	const auto speedPerSecond = 20.f;
	float dx = mouse.getDirection().x;
	float dy = mouse.getDirection().y;
	sf::Vector2f direction;

	if (dx == -1 && dy == 0) { // LEFT
		direction = { 1,0 };
	}
	else if (dx == 1 && dy == 0) { // Right
		direction = { -1,0 };
	}
	else if (dx == 0 && dy == -1) { // Up
		direction = { 0,1 };
	}
	else if (dx == 0 && dy == 1) { // Down
		direction = { 0,-1 };
	}
	//mouse.SetDirection({0,-1});
	mouse.getsprite().move(direction * speedPerSecond * mouse.getDelteTime().asSeconds());
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
