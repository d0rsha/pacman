#ifndef POWERUP_H
#define POWERUP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pacman.h"

class Powerup
{
public:
   ~Powerup() {}
   Powerup(sf::Vector2f p);
   bool check(Pacman const & p);
   Powerup& operator++();
   sf::Vector2f position;
   bool taken;
private:
   sf::Sprite sprite;
};
#endif
