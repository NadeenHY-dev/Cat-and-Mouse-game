#pragma once

#include"Icons.h"
#include <SFML/Graphics.hpp>
#include<string>


class Mouse;
class Cat;
class Cheese;
class Door;
class Gift;
class Wall;
class Key;


class Object // wall , cheeses .... 
{
public:
	Object();
	~Object();

	bool collidesWith(Object&);

	void draw(sf::RenderWindow& window) {
		window.draw(m_sprite);
	}
	void setSprite(sf::Sprite);
	sf::Sprite getsprite(); // 

	virtual void collide(Object&) = 0;
	virtual void collide(Mouse&) = 0;
	virtual void collide(Cat&) = 0;
	virtual void collide(Cheese&) = 0;
	virtual void collide(Wall&) = 0;
	virtual void collide(Gift&) = 0;
	virtual void collide(Door&) = 0;
	virtual void collide(Key&) = 0;





protected:
	sf::Sprite m_sprite;
};

