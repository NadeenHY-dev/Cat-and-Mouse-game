#pragma once

#include"Board.h"
#include"Menu.h"
#include <SFML/Graphics.hpp>
#include"Consts.h"
#include "Cat.h"
#include "Mouse.h"
#include <string>
//# include <fstream>


class Controller
{
public:
	Controller();
	~Controller();
	void displayHelp(sf::RenderWindow& window);
	void Run();

private:
	void resetGame();
	bool setLevel();
	void dealWithMenu( bool&gameRunning,sf:: RenderWindow&window);

	std::string m_level;
	Board m_board;
	Menu m_menu;
	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cat;


};