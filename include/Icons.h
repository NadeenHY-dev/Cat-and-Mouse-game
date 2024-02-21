#pragma once

#include <SFML/Graphics.hpp>


class Icons  // singleton
{
public:
	/*~Icons();*/
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

