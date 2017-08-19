#ifndef WALL_H
#define WALL_H

#include "Powerup.h"

class Wall : public Powerup
{
public:
   Wall(sf::Vector2f p)
      :Powerup(p)
      {}
   Wall& operator++()
      {
         Powerup::taken = false;
         return *this;
      }
private:
};

#endif
