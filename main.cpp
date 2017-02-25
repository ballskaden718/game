#include <iostream>
#include <SFML/Graphics.hpp>

#define HIGH 800
#define WIDE 800


int main ()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "temp");

  sf::CircleShape circle(50);
  circle.setFillColor(sf::Color::White );
  circle.setPosition(100,100);
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
      circle.move(.5, 0);
    }
    else
    {
      circle.move(-.5, 0);
    }

    //render

    window.clear(sf::Color::Blue);
    window.draw(circle);
    window.display();
  }
}
