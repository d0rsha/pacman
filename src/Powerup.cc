#include "Powerup.h"

Powerup::Powerup(sf::Vector2f p)
   : position{p}, taken{false}, sprite{}
{}

bool Powerup::check(Pacman const & p)
{
   return p.check(position);
}

Powerup& Powerup::operator++()
{
   taken = false;
   return *this;
}
