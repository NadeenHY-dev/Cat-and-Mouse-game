#pragma once

#include"Icons.h"
#include <SFML/Graphics.hpp>
#include<string>




class Object // wall , cheeses .... 
{
public:
	Object();
	~Object();
	virtual void draw() = 0;
	//void createShape(const std::string name); // 

	void setSprite(sf::Sprite);
	sf::Sprite getsprite(); // 


protected:
	sf::Sprite m_sprite;
};

