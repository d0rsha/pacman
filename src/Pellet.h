#ifndef PELLET_H
#define PELLET_H

#include "Powerup.h"

class Pellet : public Powerup
{
public:
   Pellet(sf::Vector2f p)
      :Powerup(p)
      {}
   Pellet& operator++()
      {
         std::cout << "Power pellet picked up!!\n";
      }
private:
   int piddyTime{10};
};

#endif
