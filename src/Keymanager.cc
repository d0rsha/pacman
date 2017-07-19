#include "Keymanager.h"

void Keymanager::update(sf::Keyboard::Key in)
{
   input = in;
}

sf::Keyboard::Key Keymanager::getKey()
{
   return input;
}

sf::Keyboard::Key Keymanager::input{};
