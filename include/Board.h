#pragma once

#include<iostream>
#include<fstream>

#include<vector>
#include<memory>


class Object;
//#include"Object.h"
//#include"Mouse.h"
//#include"Cat.h"




class Board
{
public:
	Board();
	~Board();

	void readToFile(size_t i);


private:
	void insertIcon(const char, size_t,size_t); // private


	std::vector<std::vector<std::unique_ptr<Object> > > m_board; // V ?
	size_t m_maxRow;
	size_t m_maxCol;

};
