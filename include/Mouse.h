#pragma once

#include"MovingObject.h"

class Mouse : public MovingObject
{
public:
	Mouse();
	Mouse(sf::Vector2f v) { 
		m_sprite = Icons::instance().getIcon(MOUSE);
		m_sprite.setPosition(v);
	}
	~Mouse() { ; }

	void setDirection(sf::Keyboard::Key key);

	sf::Vector2f getMousePosition();

	void SetDirection(sf::Vector2f v) {
		m_direction = v;
	}
	sf::Vector2f getDirection() {
		return m_direction;
	}

	sf::Time getDelteTime() {
		return m_deltaTime;
	}

	void stopMouse() {
		m_direction = { 0,0 };
	}

	virtual void collide(Object&);
	virtual void collide(Mouse&);
	virtual void collide(Cat&);
	virtual void collide(Cheese&);
	virtual void collide(Wall&);
	virtual void collide(Gift&);
	virtual void collide(Door&);
	virtual void collide(Key&);
private:

};

