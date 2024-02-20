#pragma once

#include"Board.h"
#include"Menu.h"
#include <SFML/Graphics.hpp>
#include"Consts.h"



class Controller
{
public:
	Controller();
	~Controller();

	void Run();

private:
    sf::RenderWindow m_window;
    Board m_board;



};

