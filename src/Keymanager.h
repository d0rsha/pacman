#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <SFML/Window/Event.hpp>

class Keymanager
{
public:
   Keymanager()
      :input{}
      {}
   void update(sf::Keyboard::Key in)
      {
         input = in;
      }
   sf::Keyboard::Key getKey()
      {
         return input;
      }
private:
   sf::Keyboard::Key input;
};

#endif
