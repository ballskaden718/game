#include <iostream>
#include <SFML/Graphics.hpp>

#define HIGH 800
#define WIDE 800

#define TILESIZE 160


int main ()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "temp");

  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100,100);

  sf::Texture pixie_texture;
  if(!pixie_texture.loadFromFile("assets/pixie.png"))
    {
      std::cout << "Error loading hero texture!" <<std::endl;
    }
    sf::Sprite pixie;
    pixie.setTexture(pixie_texture);
    pixie.setScale(sf::Vector2f(5,5));

  int herospeed = 1;

  int points = 5;

  int circleDir = 0;
  //game loop
  while(window.isOpen() )
  {
    //handle events
    sf::Event event;
    while(window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pixie.getPosition().y > 0)
        {
          pixie.move(0,-herospeed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pixie.getPosition().y < HIGH-TILESIZE)
        {
          pixie.move(0,herospeed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& pixie.getPosition().x < WIDE-TILESIZE)
        {
          pixie.move(herospeed,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pixie.getPosition().x > 0)
        {
          pixie.move(-herospeed,0);
        }

        if(pixie.getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
          //std::cout << "DONT TOUCH ME!!!" <<std::endl;
        }

        {
          //std::cout << "computers" << std::endl;
        }

    window.clear(sf::Color::Blue);

    //update
    if(circle.getPosition().x > WIDE-100)
    {
      circleDir = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDir = 0;
    }
    if(circleDir == 0)
    {
      circle.move(1, 0);
    }
    else
    {
      circle.move(-1, 0);
    }
    //render


    window.draw(pixie);
    window.draw(circle);
    window.display();
  }
}
