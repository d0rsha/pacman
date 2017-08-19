#ifndef POINT_H
#define POINT_H

#include "Powerup.h"

class Point : public Powerup
{
public:
   Point(sf::Vector2f p)
      :Powerup(p)
      {}
   Point& operator++()
      {
         std::cout << "Picked up one point :) \n";
      }
private:
   int bonus{5};
};

#endif
