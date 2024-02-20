#pragma once

#include"StaticObject.h"

class Wall : public StaticObject {
public:
    Wall(sf::Texture& texture) : StaticObject(texture) {}
};