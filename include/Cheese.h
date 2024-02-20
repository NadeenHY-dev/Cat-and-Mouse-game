#pragma once

#include"StaticObject.h"

class Cheese : public StaticObject {
public:
    Cheese(sf::Texture& texture) : StaticObject(texture) {  }
};