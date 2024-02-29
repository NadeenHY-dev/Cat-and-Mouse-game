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

sf::Vector2f Mouse::getMousePosition()
{
	return m_sprite.getPosition();
}

void Mouse::collide(Object& obj) 
{
	obj.collide(*this);
 }

void Mouse::collide(Mouse&)
{
}

void Mouse::collide(Cat&)
{
	m_live--;
}

void Mouse::collide(Cheese&)
{
}

void Mouse::collide(Wall&)
{
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


