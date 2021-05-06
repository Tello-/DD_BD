#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <time.h>
#include <math.h>
#include <Windows.h>






void processInput();
void update();
void render( sf::RenderWindow&, sf::Time);





int main()
{
     
     sf::RenderWindow window{ sf::VideoMode{600,600}, "Game Loop Test" };

 
     sf::Time lag;
     sf::Time MS_PER_UPDATE = sf::milliseconds(15);
     sf::Clock clock; // starts the clock

     sf::Time elapsed;
     sf::Time uptime;
     sf::Time uptimeMax = sf::seconds(5);
     while (uptime <= uptimeMax)
     {

          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed)
                    window.close();
          }

          elapsed = clock.restart();
          uptime += elapsed;
          lag += elapsed;
          processInput();
          while (lag >= MS_PER_UPDATE)
          {
               update();
               lag -= MS_PER_UPDATE;
          }
          sf::Time lagXfixed = sf::milliseconds(lag.asMilliseconds() / MS_PER_UPDATE.asMilliseconds());
          render(window, lagXfixed);
          
     }
     return 0;
}
void processInput()
{
     std::cout << "Input has been processed" << std::endl;
}

void update()
{
    std::cout << "Physics have been updated" << std::endl;
    

}

void render(sf::RenderWindow& window, sf::Time dt)
{
     std::cout << "Graphics have been rendered" << std::endl;
     window.clear();
     window.display();
}