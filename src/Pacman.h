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
   void setKeys(Keymanager);
   void setPos(int x, int y);

private:

};

#endif
