#include <SFML/Graphics.hpp>

int main()
{
     sf::Vector2f windowSize{ 1600,900 };

     sf::RenderWindow window(sf::VideoMode(int(windowSize.x), int(windowSize.y)), "Map Tester");
     
     window.setFramerateLimit(60);

     sf::Texture map;
     map.loadFromFile("map.png");

     sf::Sprite sMap;
     sMap.setTexture(map);
     sMap.setColor(sf::Color(sMap.getColor().r,sMap.getColor().g,sMap.getColor().b, 255*.65f));

     sf::View mainView{ window.getDefaultView() };

     float scaleFactor = 0.33f;
     mainView.reset(sf::FloatRect(0,0,map.getSize().x * scaleFactor, map.getSize().y * scaleFactor));
     window.setView(mainView);

     sf::View miniView(sf::FloatRect(0, 0, float(map.getSize().x), float(map.getSize().y)));
     miniView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

    
     float mapSpeed = 10;
     float boxSpeed = mapSpeed;

     sf::RectangleShape zoomBox(sf::Vector2f{ map.getSize().x * scaleFactor, map.getSize().y * scaleFactor });
     zoomBox.setFillColor(sf::Color::Transparent);
     zoomBox.setOutlineColor(sf::Color(255,255, 0, 75));
     zoomBox.setOutlineThickness(10);
     zoomBox.setPosition(sf::Vector2f(0, 0));

     while (window.isOpen())
     {
          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    window.close();
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
          {
              
               zoomBox.move(sf::Vector2f{ -1 * boxSpeed, 0.f });

               if (zoomBox.getPosition().x < 0)
               {
                    zoomBox.setPosition(sf::Vector2f(0, zoomBox.getPosition().y));
               }
               else
               {
                    mainView.move(sf::Vector2f{ -1 * mapSpeed, 0.f });
               }
               
          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
          {
               
               zoomBox.move(sf::Vector2f{ boxSpeed, 0.f });

               if (zoomBox.getPosition().x + zoomBox.getSize().x > map.getSize().x)
               {
                    zoomBox.setPosition(map.getSize().x - zoomBox.getSize().x, zoomBox.getPosition().y);
               }
               else
               {
                    mainView.move(sf::Vector2f{ mapSpeed, 0.f });
               }

          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
          {
              
               
               zoomBox.move(sf::Vector2f{ 0.f, -1 * boxSpeed });

               if (zoomBox.getPosition().y < 0)
               {
                    zoomBox.setPosition(sf::Vector2f(zoomBox.getPosition().x, 0));
               }
               else
               {
                    mainView.move(sf::Vector2f{ 0.f,-1 * mapSpeed });
               }

          }
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
          {
               zoomBox.move(sf::Vector2f{ 0.f, boxSpeed });

               if (zoomBox.getPosition().y + zoomBox.getSize().y > map.getSize().y)
               {
                    zoomBox.setPosition(zoomBox.getPosition().x, map.getSize().y - zoomBox.getSize().y);
               }
               else
               {
                    mainView.move(sf::Vector2f{ 0.f, mapSpeed });

               }
          }
          

          

          

          

          


          window.clear();
          window.setView(mainView);
          window.draw(sMap);
          window.setView(miniView);
          window.draw(sMap);
          window.draw(zoomBox);
          window.display();
     }

     return 0;
}