#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <SoundManager.h>
#include <functional>
#include <iostream>
#include"SoundManager.h"

class Menu {
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);
    ~Menu() { ; }
    // Returns the index of the selected menu item, or -1 if none
    int getSelectedItem(const sf::Vector2f& mousePos);

private:
    std::vector<sf::Text> menuTexts;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    //sf::SoundBuffer clickSoundBuffer; // to hold the sound buffer for the click sound
    // sf::Sound clickSound; //to hold the sound object for playing the click sound.
    SoundManager soundManager;
};
