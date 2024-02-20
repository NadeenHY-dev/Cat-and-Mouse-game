#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Object.h"
#include "Cat.h"
#include "Cheese.h"
#include "Door.h"
#include "Gift.h"
#include "Key.h"
#include "Mouse.h"
#include "Wall.h"



class Board {
public:
    Board(int width, int height, const sf::Texture& wallTexture, 
        const sf::Texture& doorTexture, const sf::Texture& keyTexture, 
        const sf::Texture& giftTexture, const sf::Texture& catTexture, 
        const sf::Texture& mouseTexture)
        : m_width(width), m_height(height), m_wallTexture(wallTexture), 
        m_doorTexture(doorTexture), m_keyTexture(keyTexture), 
        m_giftTexture(giftTexture), m_catTexture(catTexture), 
        m_mouseTexture(mouseTexture), 
        m_objects(width, std::vector<std::unique_ptr<Object>>(height)) {}

    void setObject(int x, int y, Object* object);
    void readToFile(size_t);
    void render(sf::RenderWindow& window);
    void setTexture();
    void createObj(char , Object*&);


private:
    int m_width;
    int m_height;

    std::vector<std::vector<std::unique_ptr<Object>>> m_objects;

    sf::Texture m_wallTexture;
    sf::Texture m_doorTexture;
    sf::Texture m_keyTexture;
    sf::Texture m_giftTexture;
    sf::Texture m_catTexture;
    sf::Texture m_mouseTexture;
};

