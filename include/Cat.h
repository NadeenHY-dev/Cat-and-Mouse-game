#pragma once

#include"MovingObject.h"

class Cat : public MovingObject {
public:
    Cat(sf::Texture& texture) : MovingObject(texture) { ; }
};