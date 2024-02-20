#pragma once

#include"StaticObject.h"

class Key : public StaticObject {
public:
    Key(sf::Texture& texture) : StaticObject(texture) {  }
};