#include "Cat.h"

class SmartCat : public Cat {
public:
    explicit SmartCat(sf::Vector2f v) : Cat(v) {}

    void move(sf::Time deltaTime) override {
        // Implement smart movement logic here
        // This is a simple example, replace it with your actual smart logic
        m_direction = sf::Vector2f(1, 0); // Just an example, moving right

        const auto speedPerSecond = 30.f; // Assuming smart cats move faster
        m_sprite.move(m_direction * speedPerSecond * deltaTime.asSeconds());
    }
};