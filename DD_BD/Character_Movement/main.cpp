#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include <iostream>

#include "Actor.hpp"


int main()
{
     sf::RenderWindow window(sf::VideoMode(600, 600), "My window");

     sf::RectangleShape hitZone;
     hitZone.setFillColor(sf::Color::Black);
     hitZone.setSize(sf::Vector2f(600, 250));
     hitZone.setPosition(0, 350);

     sf::RectangleShape freeZone;
     freeZone.setFillColor(sf::Color::White);
     freeZone.setSize(sf::Vector2f(600, 350));
     freeZone.setPosition(0, 0);


     sf::Image collImg;
     collImg.loadFromFile("collMap.png");

     sf::Texture collTex;
     collTex.loadFromImage(collImg);

     sf::Sprite collSprite;
     collSprite.setTexture(collTex);



     sf::Image blackZone;
     blackZone.create(600, 250, sf::Color::Black);

     sf::Texture blackTex;
     blackTex.loadFromImage(blackZone);

     sf::Sprite blackSprite;
     blackSprite.setTexture(blackTex);

     blackSprite.setPosition(sf::Vector2f{0.f, 350.f});


     Actor player{ sf::Vector2f{50.f, 50.f}, sf::Vector2f{50.f, 250.f}, sf::Color::Green };

     sf::Vector2f prevPos{ sf::Vector2f{50.f, 250.f} };
     sf::Vector2f currentPos{ sf::Vector2f{50.f, 250.f} };

     window.setFramerateLimit(20);
     while (window.isOpen())
     {

         
          sf::Event event;
          while (window.pollEvent(event))
          {
               // "close requested" event: we close the window
               if (event.type == sf::Event::Closed)
                    window.close();
               if (event.type == sf::Event::MouseButtonReleased)
               {

               }
          }
         
          if (prevPos == currentPos)
          {
               std::cout << "Player planted on ground" << std::endl;
          }
          prevPos = currentPos;

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
          {
               player.move(Actor::DIRECTION::UP, 10.f);
               
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
          {
               player.move(Actor::DIRECTION::DOWN, 10.f);

          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
          {
               player.move(Actor::DIRECTION::LEFT, 10.f);

          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
          {
               player.move(Actor::DIRECTION::RIGHT, 10.f);

          }


          auto collPixPtr = collImg.getPixelsPtr();



          // TODO get collision just ahead of direction of movement.
         

          



          window.clear(sf::Color{ 0,142,198, 255 });
          window.draw(collSprite);
          window.draw(player);
          window.display();



     }




     return 0;
}

