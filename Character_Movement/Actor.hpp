#pragma once

#include <SFML/Graphics.hpp>

class Actor :
	public sf::Drawable
{

public:
	Actor(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	enum DIRECTION
	{
		NONE, 
		UP, 
		DOWN, 
		LEFT, 
		RIGHT
	} currentDir;
	
	void move(DIRECTION, float dist);

	sf::Vector2f pos() const {
		return m_body.getPosition();
	}

	sf::Vector2f size() const {
		return m_body.getSize();
	}



private:
	sf::RectangleShape m_body;

};

