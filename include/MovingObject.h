#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class MovingObject : public Object {
public:
    MovingObject(sf::Texture& texture) : Object(texture) {}
};