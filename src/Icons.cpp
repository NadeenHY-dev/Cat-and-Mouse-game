#include"Icons.h"
const int SIZE = 70;

Icons::Icons()
{
	
	m_texture[CAT].loadFromFile("cat.png");
	m_texture[MOUSE].loadFromFile("mouse.png"); 
	m_texture[DOOR].loadFromFile("door.png"); 
	m_texture[WALL].loadFromFile("bush.png");
	m_texture[CHEESE].loadFromFile("cheese.png");
	m_texture[KEY].loadFromFile("key.png");
	m_texture[GIFT].loadFromFile("gift.png");


	for (int i = 0; i < NUM_OF_ICONS; i++) {
		m_sprite[i].setTexture(m_texture[i]);
		m_sprite[i].setScale((sf::Vector2f(((float)SIZE / m_sprite[i].getGlobalBounds().height),
		((float)SIZE / m_sprite[i].getGlobalBounds().height))));
	}
}


Icons& Icons::instance()
{
	static Icons obj;
	return obj;
}

sf::Sprite Icons::getIcon(tools tool)
{
	return m_sprite[tool];
}


