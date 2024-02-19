#pragma once

#include<vector>
#include<Object.h>
#include<fstream>
#include<iostream>
#include<string>
#include"Mouse.h"
#include"Cat.h"
#include"Wall.h"
#include"Door.h"
#include"Gift.h"
#include"Key.h"
#include"Cheese.h"
#include<memory>


class Board
{
public:
	Board();
	~Board();

	void readToFile(size_t i);

	//void draw()


private:
	void insertIcon(const char, size_t,size_t); // private


	std::vector<std::vector<std::unique_ptr<Object> > > m_board; // V ?
	//std::vector<std::string> m_board; // V ?
	size_t m_maxRow;
	size_t m_maxCol;

};
