#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DrawBuffer.h"


int main()
{

     



    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");


    // Load a sprite to display
    sf::Texture gloves;
    if (!gloves.loadFromFile("gloves.jpg"))
        return EXIT_FAILURE;
    sf::Texture ryo;
    if (!ryo.loadFromFile("ryo.jpg"))
         return EXIT_FAILURE;
    sf::Texture mario;
    if (!mario.loadFromFile("mario.jpg"))
         return EXIT_FAILURE;
    sf::Texture drum;
    if (!drum.loadFromFile("drum.jpg"))
         return EXIT_FAILURE;


    DrawBuffer buffer;

    sf::Sprite sprite1(gloves);
    sf::Sprite sprite2(ryo);
    sf::Sprite sprite3(mario);
    sf::Sprite sprite4(drum);

    buffer.pushLayer(&sprite3);
    buffer.pushLayer(&sprite4);
    buffer.pushLayer(&sprite1);
    buffer.pushLayer(&sprite2);
    
    // Create a graphical text to display
   
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(buffer);
       
        window.display();
    }
    return EXIT_SUCCESS;
}