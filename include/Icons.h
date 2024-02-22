#pragma once

#include <SFML/Graphics.hpp>

const int NUM_OF_ICONS = 8;
enum tools
{
	MOUSE, CAT, CHEESE, DOOR, KEY, GIFT, WALL ,ROAD
};

class Icons  // singleton
{
public:
	static Icons& instance();

	sf::Sprite getIcon(tools);

private:
	Icons();

	sf::Texture m_texture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];
	std::string m_nameFiles[NUM_OF_ICONS];
};

