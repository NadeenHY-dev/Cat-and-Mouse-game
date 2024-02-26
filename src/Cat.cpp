#include "Cat.h"

sf::Vector2f Cat::getCatPosition()
{
    return m_sprite.getPosition();
}
//
//void Cat::SetDirection(sf::Vector2f MousePlace)
//{
//	sf::Vector2f CatPosition = m_sprite.getPosition();
//	double Up = distance({ CatPosition.x ,CatPosition.y - 1}, MousePlace);
//	double Down = distance({ CatPosition.x ,CatPosition.y + 1 }, MousePlace);
//	double Right = distance({ CatPosition.x + 1,CatPosition.y }, MousePlace);
//	double Left = distance({ CatPosition.x - 1,CatPosition.y }, MousePlace);
//
//	double minDistance = std::min(std::min(Up, Down), std::min(Right, Left));
//
//	if (Up == minDistance)
//		m_direction = { 0 ,- 1 };
//	else if (Down == minDistance)
//		m_direction = { 0 , 1 };
//	else if (Right == minDistance)
//		m_direction = { 1, 0 };
//	else
//		m_direction = { - 1, 0 };
//}
//
double Cat::distance(sf::Vector2f p1, sf::Vector2f p2)
{
	return sqrt(pow(p1.y - p2.y, 2) + pow(p1.x - p2.x, 2));
}

#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

void Cat::SetDirection(sf::Vector2f MousePlace)
{
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 0 and 99
    int randomChance = std::rand() % 100;

    // Determine whether the cat should move randomly or towards the mouse
    if (randomChance > 30) // Adjust the probability as needed (e.g., 20% chance here)
    {
        // Random step
        int randomDirection = std::rand() % 4; // Randomly choose a direction (up, down, left, right)
        switch (randomDirection)
        {
        case 0:
            m_direction = { 0, -1 }; // Up
            break;
        case 1:
            m_direction = { 0, 1 };  // Down
            break;
        case 2:
            m_direction = { 1, 0 };  // Right
            break;
        case 3:
            m_direction = { -1, 0 }; // Left
            break;
        }
    }
    else
    {
        // Move towards the mouse
        sf::Vector2f CatPosition = m_sprite.getPosition();
        double Up = distance({ CatPosition.x ,CatPosition.y - 1 }, MousePlace);
        double Down = distance({ CatPosition.x ,CatPosition.y + 1 }, MousePlace);
        double Right = distance({ CatPosition.x + 1,CatPosition.y }, MousePlace);
        double Left = distance({ CatPosition.x - 1,CatPosition.y }, MousePlace);

        double minDistance = std::min(std::min(Up, Down), std::min(Right, Left));

        if (Up == minDistance)
            m_direction = { 0 ,-1 };
        else if (Down == minDistance)
            m_direction = { 0 , 1 };
        else if (Right == minDistance)
            m_direction = { 1, 0 };
        else
            m_direction = { -1, 0 };
    }

}
