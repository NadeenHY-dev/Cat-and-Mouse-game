#pragma once

#include"Icons.h"
#include <SFML/Graphics.hpp>
#include<string>




class Object // wall , cheeses .... 
{
public:
	Object();
	~Object();
	void draw(sf::RenderWindow& window) {
		window.draw(m_sprite);
	}
	void setSprite(sf::Sprite);
	sf::Sprite getsprite(); // 


protected:
	sf::Sprite m_sprite;
};

