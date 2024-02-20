#pragma once

#include"StaticObject.h"

class Gift : public StaticObject {
public:
    Gift(sf::Texture& texture) : StaticObject(texture) {}
};