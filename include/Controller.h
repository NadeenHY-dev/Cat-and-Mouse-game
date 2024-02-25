#pragma once

#include"Board.h"
#include"Menu.h"
#include <SFML/Graphics.hpp>
#include"Consts.h"
#include "Cat.h"
#include "SmartCat.h" // Include SmartCat header
#include "NormalCat.h" // Include NormalCat header
#include "Mouse.h"
#include <string>
//# include <fstream>


class Controller
{
public:
	Controller();
	~Controller();

	void Run();

private:
	bool setLevel();
	void loadCats();
	std::string m_level;
	Board m_board;
	//Menu m_menu;
	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cat;


};