#include <iostream>
#include <SFML/Graphics.hpp>

#define HIGH 800
#define WIDE 800


int main ()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "temp");

  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100,100);

  sf::RectangleShape pixie(sf::Vector2f(100,100));
  pixie.setFillColor(sf::Color::Black);
  pixie.setPosition(WIDE-100,HIGH-100);
  int circleDir = 100;

  int herospeed = 1;

  int points = 5;
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pixie.getPosition().y < HIGH-pixie.getSize().y)
        {
          pixie.move(0,herospeed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& pixie.getPosition().x < WIDE-pixie.getSize().x)
        {
          pixie.move(herospeed,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pixie.getPosition().x > 0)
        {
          pixie.move(-herospeed,0);
        }

        if(pixie.getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
          std::cout << "DONT TOUCH ME!!!" <<std::endl;
        }

        {
          std::cout << "computers" << std::endl;
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
