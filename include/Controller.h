#pragma once

#include"Board.h"
#include"Menu.h"
#include <SFML/Graphics.hpp>
#include"Consts.h"
#include "Cat.h"
#include "Mouse.h"



class Controller
{
public:
	Controller();
	~Controller();

	void Run();

private:
	Board m_board;
	//Menu m_menu;
	Mouse m_mouse;
	std::vector<Cat> m_cat;
};

