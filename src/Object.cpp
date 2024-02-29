#include "Object.h"
Object::Object()
{
	
}

Object::~Object()
{
}

bool Object::collidesWith(Object& obj)
{
	return m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());
}

//void Object::createShape(const std::string name)
//{
//	sf::Texture texture;
//	texture.loadFromFile(name); // ??
//	m_sprite.setTexture(texture);
//}

sf::Sprite Object::getsprite()
{
	return m_sprite ;
}

void Object::setSprite(sf::Sprite sprite)
{
	//const Icons& r = Icons::sprite_cat();
	//m_sprite = r.sprite_cheese();  // Icons::sprite();
	
}
