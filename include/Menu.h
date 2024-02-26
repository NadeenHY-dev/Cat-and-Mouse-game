#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

class Menu {
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);

    // Returns the index of the selected menu item, or -1 if none
    int getSelectedItem(const sf::Vector2f& mousePos);

private:
    std::vector<sf::Text> menuTexts;
    sf::Font font;
};
