#pragma once
#include <vector>
#include <SFML/Graphics.hpp>



class DrawBuffer : public sf::Drawable
{
public:

	virtual			~DrawBuffer() {}
	virtual	void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
			void		pushLayer(const sf::Drawable*);

private:
	std::vector<const sf::Drawable*> m_layers;
	
};

