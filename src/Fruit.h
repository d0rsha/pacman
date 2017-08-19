#ifndef FRUIT_H
#define FRUIT_H

#include "Powerup.h"

class Fruit : public Powerup
{
public:
Fruit(sf::Vector2f p)
   :Powerup(p)
{}
Fruit& operator++()
{
std::cout << "Fruit picked up!!\n";
return *this;
}
private:
int bonus{100};
};

#endif
