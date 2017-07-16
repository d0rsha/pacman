#include <SFML/Graphics.hpp>
#include "Chart.h"
#include <string>

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "pacMan");

   while (window.isOpen())
   {
      sf::Event event;
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            window.close();
      }
      window.display();
      }
   return 0;
}
