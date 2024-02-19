#pragma once

#include <SFML/Graphics.hpp>
#include<string>

class Object // wall , cheeses .... 
{
public:
	Object();
	~Object();
	
	void createShape(const std::string name); // 
	sf::Sprite getsprite(); // 

	void setSprite(sf::Sprite);


protected:
	sf::Sprite m_sprite;
};

