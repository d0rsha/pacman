#include <SFML/Graphics.hpp>
#include "Chart.h"
#include "Keymanager.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "pacMan");
  window.setFramerateLimit(30);
  
  Chart chart;
  //Keymanager key;
  chart.init();
  bool focus{true};
  
   while (window.isOpen())
   {
      //Event handler
      sf::Event event;
      while (window.pollEvent(event))
      {
         switch(event.type)
         {
         case sf::Event::Closed:
            cout << "Game closed\n";
            window.close();
         case sf::Event::KeyPressed:
            // cout << "Keypressed: " << static_cast<char>(event.key.code + 65) << endl;
            Keymanager::update(event.key.code);
         default:
            ;
         }
         if (event.type == sf::Event::LostFocus) {
            ;//Pause game
           focus = false;
            cout << "Game paused\n";
         }
         if ( event.type == sf::Event::GainedFocus) {
            ;// Resume game
           focus = true;
            cout << "Game resumed\n";
         }
         if (event.type == sf::Event::Resized) {
            cout << "new width: " << event.size.width << endl;
            cout << "new height " << event.size.height << endl;
         }
            
         
         if (event.type == sf::Event::Closed)
            window.close();
      }
      // Clear screen
      window.clear(sf::Color::Black);
    
     if (focus)
     {
      // Update stuff
      chart.update();
     }
      // Draw stuff
      chart.draw(&window);
      // Display stuff
      window.display();

      }

   return 0;
}
