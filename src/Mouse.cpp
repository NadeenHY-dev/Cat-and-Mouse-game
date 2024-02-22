#include "Mouse.h"

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

void Mouse::move(sf::Time deltatime)
{
	const auto speedPerSecond = 20.f;
	m_sprite.move(m_direction * speedPerSecond * deltatime.asSeconds());
}


