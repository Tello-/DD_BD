/* This file is the main entry point for the 
project concerning working with collision maps 
and relating them to the graphical representation 
it is signifying*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DrawBuffer.h"


#include <iostream>
#include <SFML/Graphics.hpp>



void stampLocation(sf::Vector2i, sf::Vector2f, sf::Image* img, sf::Color color = sf::Color::Transparent);




int main()
{
     sf::Texture skyTexture;
     sf::Sprite skySprite;
     sf::Image foreImg;

     sf::Texture foreTexture;
     sf::Sprite foreSprite;
     sf::Image collMapImg;
     sf::Texture collMapTex;
     sf::Sprite collMapSprite;
     sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
     sf::Sprite* activeSprite = &foreSprite;
     sf::RectangleShape mass;

     sf::Color currentPixel;
     bool hitDetected = false;
     float massSpeed = 10.0f;
     bool shouldStart = false;
     

     
     skyTexture.loadFromFile("bg.png");
     skySprite.setTexture(skyTexture);


     
     foreImg.loadFromFile("fg.png");
     foreTexture.loadFromImage(foreImg);
     foreSprite.setTexture(foreTexture);

     sf::Image foreCopy(foreImg);

     collMapImg.loadFromFile("collmap.png");

     collMapTex.loadFromImage(collMapImg);

     collMapSprite.setTexture(collMapTex);

     sf::Image collCopyImg(collMapImg);


     mass.setSize(sf::Vector2f{ 50,50 });
     mass.setPosition(300 - 25, 0);
     mass.setFillColor(sf::Color(200, 200, 0, 255));
     sf::Vector2f massPos{ window.getSize().x / 2 - mass.getSize().x / 2 , 0.f};


     window.setFramerateLimit(20);

     
     while (window.isOpen())
     {
          
          sf::Vector2i clickLocation;
          // check all the window's events that were triggered since the last iteration of the loop
          sf::Event event;
          while (window.pollEvent(event))
          {
               // "close requested" event: we close the window
               if (event.type == sf::Event::Closed)
                    window.close();
               if (event.type == sf::Event::MouseButtonReleased)
               {
                    if (event.mouseButton.button == sf::Mouse::Button::Right)
                    {
                         if (activeSprite == &collMapSprite)
                         {
                              activeSprite = &foreSprite;
                         }
                         else
                         {
                              activeSprite = &collMapSprite;
                         }

                    }
                    else
                    {
                         std::cout << "Mouse Button Released" << std::endl;
                    }
                    
               }
               if (event.type == sf::Event::KeyReleased)
               {
                    if (event.key.code == sf::Keyboard::Key::R)
                    {
                         collMapImg.copy(collCopyImg, 0,0);
                         foreImg.copy(foreCopy, 0,0);

                         foreTexture.loadFromImage(foreImg);
                         foreSprite.setTexture(foreTexture);
                         
                         collMapTex.loadFromImage(collMapImg);
                         collMapSprite.setTexture(collMapTex);
                         
                         mass.setPosition(massPos);

                         shouldStart = false;
                         hitDetected = false;
                    }
               }
          }

          if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
          {
               std::cout << "Left Button Pressed" << std::endl;
               clickLocation = sf::Mouse::getPosition(window);
               std::cout << "x: " << clickLocation.x << " y: " << clickLocation.y << std::endl;
               stampLocation(clickLocation, sf::Vector2f{100,50}, &collMapImg, sf::Color::White);
               stampLocation(clickLocation, sf::Vector2f{ 100,50 }, &foreImg);
               collMapTex.update(collMapImg);
               foreTexture.update(foreImg);
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
               shouldStart = true;
          }



          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
          {
               mass.move(sf::Vector2f{ 0.f, -1 * massSpeed});

          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
          {
               mass.move(sf::Vector2f{ 0.0f,massSpeed });
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
          {
               mass.move(sf::Vector2f{ -1 * massSpeed, 0.f });
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
          {
               mass.move(sf::Vector2f{ massSpeed, 0.f });
          }


          if (!hitDetected && shouldStart) mass.move(0, massSpeed);
          for (int i = mass.getPosition().x; i <= mass.getPosition().x + mass.getSize().x; ++i)
          {
               for (int j = mass.getPosition().y; j <= mass.getPosition().y + mass.getSize().y; ++j)
               {
                    if (collMapImg.getPixel(i, j) == sf::Color::Black)
                    {
                         hitDetected = true;

                    }
                    if (hitDetected) break;
               }
               if (hitDetected) break;
          }

          window.clear(sf::Color{ 0,142,198, 255 });
          window.draw(skySprite);
          window.draw(*activeSprite);
          window.draw(mass);
          window.display();



     }


     
     
     return 0;
}



void stampLocation(sf::Vector2i loc, sf::Vector2f side, sf::Image* img, sf::Color color)
{
     int horizontalRangeMin;
     int verticalRangeMin;

     int horizontalRangeMax;
     int verticalRangeMax;


     horizontalRangeMin = loc.x - side.x / 2; // rightmost edge
     horizontalRangeMax = loc.x + side.x / 2;

     verticalRangeMin = loc.y - side.y / 2; // bottommost edge
     verticalRangeMax = loc.y + side.y / 2;

     for (int i = horizontalRangeMin; i <= horizontalRangeMax; ++i)
     {
          for (int j = verticalRangeMin; j <= verticalRangeMax; ++j)
          {
               img->setPixel(i, j, color);
          }
     }


}
