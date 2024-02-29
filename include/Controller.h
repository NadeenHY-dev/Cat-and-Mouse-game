#pragma once
#include <SFML/Audio.hpp>

#include"Board.h"
#include"Menu.h"
#include <SFML/Graphics.hpp>
#include"Consts.h"
#include "Cat.h"
#include "SoundManager.h"
#include "Mouse.h"
#include <string>
#include <iostream>


class Controller
{
public:
	Controller();
	~Controller();
	void displayHelp(sf::RenderWindow& window);
	void Run();


private:
	void handleCollesion(Object&);
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	void loadMoveableObj();

	void resetGame();
	bool setLevel();
	void dealWithMenu( bool&gameRunning,sf:: RenderWindow&window);

	std::string m_level;
	Board m_board;
	Menu m_menu;
	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cat;
	bool gameRunning = false;
};