#include "Menu.h"

Menu::Menu(float width, float height) 
{

    // Load the texture for the background photo
    if (!backgroundTexture.loadFromFile("jungle.jpg")) {
        std::cerr << "Failed to load background image\n";
    }

    // Set the texture for the background sprite
    backgroundSprite.setTexture(backgroundTexture);

    // Scale the background sprite to cover the entire window
    float scaleX = width / backgroundSprite.getLocalBounds().width;
    float scaleY = height / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "faild loading";

    }


    std::string menuItems[] = { "Play", "Help", "Exit" };
    for (int i = 0; i < 3; ++i) {
        for (int i = 0; i < 3; ++i) {
            sf::Text text(menuItems[i], font, 24);
            // Center the text horizontally and vertically
            sf::FloatRect textBounds = text.getLocalBounds();
            text.setOrigin(textBounds.width / 2, textBounds.height / 2);
            text.setPosition(sf::Vector2f(width / 2, height / 4 * (i + 1)));
            text.setFillColor(sf::Color::White);
            menuTexts.push_back(text);
        }
    }
}

void Menu::draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);

    for (auto& text : menuTexts) {
        window.draw(text);
    }
}

int Menu::getSelectedItem(const sf::Vector2f& mousePos)
{
    for (size_t i = 0; i < menuTexts.size(); ++i) {
        if (menuTexts[i].getGlobalBounds().contains(mousePos)) {
            // Play the click sound when a menu item is selected
            soundManager.loadSound("click", "menuclick.ogg");
            soundManager.playSound("click");
            return i;
        }
    }
    return -1;
}