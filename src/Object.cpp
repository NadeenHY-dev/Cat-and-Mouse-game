#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::createShape(const std::string name)
{
	sf::Texture texture;
	texture.loadFromFile(name); // ??
	m_sprite.setTexture(texture);
}

sf::Sprite Object::getsprite()
{
	return m_sprite ;
}

void Object::setSprite(sf::Sprite sprite)
{
	m_sprite = sprite;
}
