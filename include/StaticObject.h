#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class StaticObject : public Object {
public:
    StaticObject(sf::Texture& texture) : Object(texture) {}
};