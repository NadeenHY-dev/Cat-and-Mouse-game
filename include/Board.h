#pragma once

#include<iostream>
#include<fstream>

#include<vector>
#include<memory>

#include<string>
#include"Wall.h"
#include"Door.h"
#include"Gift.h"
#include"Key.h"

#include"Cheese.h"
class Object;
#include"Mouse.h"
#include"Cat.h"


const int SIZE = 80;

class Board
{
public:
	Board();
	~Board();

	size_t getRow();
	size_t getCol();

	Object& getObj(size_t i, size_t j);

	void readToFile(const std::string level_name,Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cat 
		            , std::vector<std::unique_ptr<StaticObject>>&);
	void printer(sf::RenderWindow& window);
	bool notInRange(sf::Vector2f position) const;
private:
	void insertIcon(const char, size_t,size_t, Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cat
					, std::vector<std::unique_ptr<StaticObject>>&); // private

	void setBackGround();

	std::vector<std::vector<std::unique_ptr<Object> > > m_board; // V ?
	size_t m_maxRow;
	size_t m_maxCol;

	sf::Time m_time;

	sf::Texture backgroundTexture; // Texture for the background image
	sf::Sprite backgroundSprite; // Sprite using the texture
};