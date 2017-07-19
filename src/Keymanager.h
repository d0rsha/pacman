#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#include <SFML/Window/Event.hpp>

class Keymanager
{
public:
   static void update(sf::Keyboard::Key in); 
   static sf::Keyboard::Key getKey();
   static  sf::Keyboard::Key input;
};

#endif
