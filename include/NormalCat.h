//#pragma once
//
//#include "Cat.h"
//
//class NormalCat : public Cat
//{
//public:
//    explicit NormalCat(sf::Vector2f v) : Cat(v) {}
//
//    void move(sf::Time deltaTime) override {
//        // Implement smart movement logic here
//        // This is a simple example, replace it with your actual smart logic
//        m_direction = sf::Vector2f(1, 0); 
//
//
//        sf::Vector2f step;
//        step = sf::Vector2f(1, 0); //right
//
//
//
//        const auto speedPerSecond = 30.f; 
//        m_sprite.move(m_direction * speedPerSecond * deltaTime.asSeconds());
//    }
//};