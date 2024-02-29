#include "Mouse.h"
//sf::Keyboard::Key
void Mouse::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Space:
		m_direction = sf::Vector2f(0, 0);
		break;
	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0); // V
		break;
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0);
		break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1); // V maybe we have to change it 
		break;
	case sf::Keyboard::Key::Up: 
		m_direction = sf::Vector2f(0, -1);
		break;
	default:
		break;
	}
}


//we have to check on what the mouse has stepped on and then chande the position
//void Mouse::move(sf::Time deltatime)
//{
//	const auto speedPerSecond = 20.f;
//	m_sprite.move(m_direction * speedPerSecond * deltatime.asSeconds());
//}

sf::Vector2f Mouse::getMousePosition()
{
	return m_sprite.getPosition();
}

void Mouse::collide(Object& obj) // Wall
{
	obj.collide(*this);
 }

void Mouse::collide(Mouse&)// maybe we have to remove it 
{
}

void Mouse::collide(Cat&)
{
}

void Mouse::collide(Cheese&)
{
}

void Mouse::collide(Wall&)
{
	//const auto speedPerSecond = 20.f;
	//float dx = m_direction.x;
	//float dy = m_direction.y;

	////if (dx == -1 && dy == 0) { // LEFT
	////	m_direction = { 1,0 };
	////}
	////else if (dx == 1 && dy == 0) { // Right
	////	m_direction = { -1,0 };
	////}
	////else if (dx == 0 && dy == -1) { // Up
	////	m_direction = { 0,1 };
	////}
	////else if (dx == 0 && dy == 1) { // Down
	////	m_direction = { 0,-1 };
	////}
	////else;
	//	m_sprite.move(-m_direction * speedPerSecond * m_deltaTime.asSeconds());
}

void Mouse::collide(Gift&)
{
}

void Mouse::collide(Door&)
{
}

void Mouse::collide(Key&)
{
}


