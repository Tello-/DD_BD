#include "Actor.hpp"



Actor::Actor(sf::Vector2f size, sf::Vector2f pos, sf::Color color = sf::Color::Green) : currentDir{ NONE }
{
	m_body.setFillColor(color);
	m_body.setSize(size);
	m_body.setPosition(pos);
}

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_body, states);
}

void Actor::move(DIRECTION dir, float dist)
{
	switch (dir)	
	{
	case Actor::NONE:
		break;
	case Actor::UP:
		m_body.move(sf::Vector2f{ 0.f, -dist });
		break;
	case Actor::DOWN:
		m_body.move(sf::Vector2f{ 0.f, dist });
		break;
	case Actor::LEFT:
		m_body.move(sf::Vector2f{ -dist, 0.f});
		break;
	case Actor::RIGHT:
		m_body.move(sf::Vector2f{ dist, 0.f });
		break;
	default:
		break;
	}

}
