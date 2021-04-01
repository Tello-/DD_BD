#include "DrawBuffer.h"

void DrawBuffer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto iter : m_layers)
	{
		target.draw(*iter, states);
	}
}

void DrawBuffer::pushLayer(const sf::Drawable* newLayer)
{
	m_layers.push_back(newLayer);
}