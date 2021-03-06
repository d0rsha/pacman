#ifndef PACMAN_H
#define PACMAN_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "Animation.h"
#include "Keymanager.h"

#include <list>
class Pacman : public Animation
{
public:
   Pacman(std::list<Entity*>* list);
   virtual void update() final;
   void setKeys();
   void setPos(int x, int y);

   // sf::Vector2f getPos() const { return Entity::getPosition(); }
   bool check(sf::Vector2f p) const { return Entity::getPosition() == p;} 
private:

};

#endif
