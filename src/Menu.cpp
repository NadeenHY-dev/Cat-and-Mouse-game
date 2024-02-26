#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.png")) {
        // Handle error
    }

    std::string menuItems[] = { "New Game", "Help", "Exit" };
    for (int i = 0; i < 3; ++i) {
        sf::Text text(menuItems[i], font, 24);
        text.setPosition(sf::Vector2f(width / 2, height / (4) * (i + 1)));
        text.setFillColor(sf::Color::White);
        menuTexts.push_back(text);
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    for (auto& text : menuTexts) {
        window.draw(text);
    }
}

int Menu::getSelectedItem(const sf::Vector2f& mousePos)
{
    for (size_t i = 0; i < menuTexts.size(); ++i) {
        if (menuTexts[i].getGlobalBounds().contains(mousePos)) {
            return i;
        }
    }
    return -1;
}