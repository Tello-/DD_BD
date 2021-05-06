#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Player
{
public:
	Player();
private:
	sf::RectangleShape m_shape;
	sf::Vector2f m_center;
	sf::Vector2f m_size;
	sf::Color m_fillColor;
	sf::Color m_outlineColor;
	float m_outlineThickness;
};
class Game
{
public:
	Game();
private:
};

