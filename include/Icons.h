#pragma once

#include <SFML/Graphics.hpp>


class Icons  // singleton
{
public:
	//~Icons();
	static Icons& instance();

	sf::Sprite sprite_cat();
	sf::Sprite sprite_mouse();
	sf::Sprite sprite_wall();
	sf::Sprite sprite_gift();
	sf::Sprite sprite_key();
	sf::Sprite sprite_cheese();
	sf::Sprite sprite_door();


private:
	Icons();

	sf::Texture m_mouse;
	sf::Texture m_cat;
	sf::Texture m_cheese;
	sf::Texture m_wall;
	sf::Texture m_key;
	sf::Texture m_gift;
	sf::Texture m_door;
	//std::vector<sf::Texture> m_arr;
};




Icons::Icons()
{
	m_cat.loadFromFile("cat.png");
	m_mouse.loadFromFile("mouse.png");
	m_door.loadFromFile("door.png");
	m_wall.loadFromFile("wall.png");
	m_cheese.loadFromFile("cheese.png");
	m_key.loadFromFile("key.png");
	m_gift.loadFromFile("gift.png");
}

//Icons::~Icons()
//{
//}

inline Icons& Icons::instance()
{
	static Icons obj;
	return obj;
}

inline sf::Sprite Icons::sprite_cat()
{
	sf::Sprite sprite;
	sprite.setTexture(m_cat);
	return sprite;
}

inline sf::Sprite Icons::sprite_mouse()
{
	sf::Sprite sprite;
	sprite.setTexture(m_mouse);
	return sprite;
}

inline sf::Sprite Icons::sprite_wall()
{
	sf::Sprite sprite;
	sprite.setTexture(m_wall);
	return sprite;
}

inline sf::Sprite Icons::sprite_gift()
{
	sf::Sprite sprite;
	sprite.setTexture(m_gift);
	return sprite;
}

inline sf::Sprite Icons::sprite_key()
{
	sf::Sprite sprite;
	sprite.setTexture(m_key);
	return sprite;
}

inline sf::Sprite Icons::sprite_cheese()
{
	sf::Sprite sprite;
	sprite.setTexture(m_cheese);
	return sprite;
}

inline sf::Sprite Icons::sprite_door()
{
	sf::Sprite sprite;
	sprite.setTexture(m_door);
	return sprite;
}
