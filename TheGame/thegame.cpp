#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <sstream>


void upPressed();
void downPressed();
void leftPressed();
void rightPressed();

void initPlayerShape();
void initImages();
void initTextures();
void initSprites();

sf::Vector2u windowSize{ 600,800 };
std::string titleString{ "Dig'n Doug and Bomb'r Dan!" };
sf::CircleShape playerShape;
sf::Color playerFillColor( sf::Color::Green );
sf::Color playerOutlineColor(sf::Color::White);
float playerRadius{25};
float playerOutlineThickness{ -3 };
sf::Vector2f playerDefaultPos{ 0,0 };

sf::Image collImg;
sf::Image bgImg;
sf::Image fgImg;

sf::Texture collTexture;
sf::Texture bgTexture;
sf::Texture fgTexture;

sf::Sprite collSprite;
sf::Sprite bgSprite;
sf::Sprite fgSprite;

float playerSpeed{ 10.f };


int main()
{
     initPlayerShape();
     initImages();
     initTextures();
     initSprites();

     sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), titleString);
     window.setFramerateLimit(60);
     while (window.isOpen())
     {
          sf::Event event;
          while (window.pollEvent(event))
          {
               if (event.type == sf::Event::Closed) window.close();              
          }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) upPressed();
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) downPressed();
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) leftPressed();
          else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) rightPressed();

          titleString = "(";
          float x = playerShape.getPosition().x;

          //..

          std::ostringstream ss;
          ss << x;
          std::string s(ss.str());
          titleString.append(s);

          titleString.append(", ");
          int y = playerShape.getPosition().y;
          std::ostringstream tt;
          tt << y;
          std::string t(tt.str());
          titleString.append(t);
          titleString.append(")");
          window.setTitle(titleString);


          window.clear();
          window.draw(bgSprite);
          window.draw(fgSprite);
          window.draw(playerShape);
          window.display();
     }

     return 0;
}

void downPressed()
{
     using namespace std;
     cout << "Down has been pressed" << endl;
     playerShape.move(sf::Vector2f{0.f, playerSpeed});
}

void upPressed()
{
     using namespace std;
     cout << "Up has been pressed" << endl;
     playerShape.move(sf::Vector2f{0.f, -1*playerSpeed});
}

void leftPressed()
{
     using namespace std;
     cout << "Left has been pressed" << endl;
     playerShape.move(sf::Vector2f{ -1 * playerSpeed , 0.f});
}

void rightPressed()
{
     using namespace std;
     cout << "Right has been pressed" << endl;
     playerShape.move(sf::Vector2f{playerSpeed, 0.f});
}

void initPlayerShape()
{
     playerShape.setFillColor(playerFillColor);
     playerShape.setPosition(playerDefaultPos);
     playerShape.setOutlineColor(playerOutlineColor);
     playerShape.setRadius(playerRadius);
     playerShape.setOutlineThickness(playerOutlineThickness);
}

void initImages()
{
     collImg.loadFromFile("collMap.png");
     bgImg.loadFromFile("bg_dirt_sky.png");
     fgImg.loadFromFile("fg_dirt.png");

}

void initTextures()
{
     collTexture.loadFromImage(collImg);
     bgTexture.loadFromImage(bgImg);
     fgTexture.loadFromImage(fgImg);
}

void initSprites()
{
     collSprite.setTexture(collTexture);
     bgSprite.setTexture(bgTexture);
     fgSprite.setTexture(fgTexture);

     fgSprite.setPosition(0 , 200);
}
