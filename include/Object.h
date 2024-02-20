#pragma once

#include <SFML/Graphics.hpp>
#include<string>
#include"Icons.h"


class Object // wall , cheeses .... 
{
public:
	Object();
	~Object();
	
	//void createShape(const std::string name); // 

	void setSprite(sf::Sprite);
	sf::Sprite getsprite(); // 


protected:
	sf::Sprite m_sprite;
};

