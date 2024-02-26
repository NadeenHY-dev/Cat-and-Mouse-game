#include "Cat.h"

void Cat::SetDirection(sf::Vector2f MousePlace)
{
	sf::Vector2f CatPosition = m_sprite.getPosition();
	double Up = distance({ CatPosition.x ,CatPosition.y - 1}, MousePlace);
	double Down = distance({ CatPosition.x ,CatPosition.y + 1 }, MousePlace);
	double Right = distance({ CatPosition.x + 1,CatPosition.y }, MousePlace);
	double Left = distance({ CatPosition.x - 1,CatPosition.y }, MousePlace);

	double minDistance = std::min(std::min(Up, Down), std::min(Right, Left));

	if (Up == minDistance)
		m_direction = { 0 ,- 1 };
	else if (Down == minDistance)
		m_direction = { 0 , 1 };
	else if (Right == minDistance)
		m_direction = { 1, 0 };
	else
		m_direction = { - 1, 0 };
}

void Cat::collide(Object& obj)
{
	obj.collide(*this);
}

void Cat::collide(Mouse&)
{
}

void Cat::collide(Cat&)
{
}

void Cat::collide(Cheese&)
{
}

void Cat::collide(Wall&)
{
}

void Cat::collide(Gift&)
{
}

void Cat::collide(Door&)
{
} 

void Cat::collide(Key&)
{
}

double Cat::distance(sf::Vector2f p1, sf::Vector2f p2)
{
	return sqrt(pow(p1.y - p2.y, 2) + pow(p1.x - p2.x, 2));
}