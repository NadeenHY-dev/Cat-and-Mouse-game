#pragma once

#include"MovingObject.h"

class Mouse : public MovingObject {
public:
    Mouse(sf::Texture& texture) : MovingObject(texture) {}
};