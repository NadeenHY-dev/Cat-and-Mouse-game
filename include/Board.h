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
//#include"Object.h"
#include"Mouse.h"
#include"Cat.h"

const int SIZE = 60;


class Board
{
public:
	Board();
	~Board();

	void readToFile(size_t i,Mouse& mouse,std::vector<Cat>& cat);
	void printer(sf::RenderWindow& window);

private:
	void insertIcon(const char, size_t,size_t, Mouse& mouse, std::vector<Cat>& cat); // private

	std::vector<std::vector<std::unique_ptr<Object> > > m_board; // V ?
	size_t m_maxRow;
	size_t m_maxCol;

};
