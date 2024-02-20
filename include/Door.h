#pragma once

#include"StaticObject.h"

class Door : public StaticObject {
public:
    Door(sf::Texture& texture) : StaticObject(texture) {}
};