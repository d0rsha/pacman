#ifndef ANIMATION_H
#define ANIMATION_H

#include "Entity.h"
#include <list>
/**
   0 - RIGHT
   1 - UP
   2 - LEFT
   3 - DOWN
**/
class Animation : public Entity
{
public:
   virtual ~Animation() {}
   Animation(std::list<Entity*>* list, sf::Vector2i sheetCoord, int ani_it_limit);
   virtual void update() override;
protected:
   sf::Vector2f direction{0, 0};
private:
   sf::Vector2i sheetCoordinate; // Coordinate on spritesheet
   bool alive{true};
   int animation_it_limit; //Max animation iterations
   int counter{};

};
#endif
