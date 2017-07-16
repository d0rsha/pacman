#ifndef ANIMATION_H
#define ANIMATION_H

#include "Entity.h"
#include <list>

class Animation : public Entity
{
public:
   virtual ~Animation() {}
   Animation(std::list<Entity*>* list, sf::Vector2i pos);
   virtual void update() override;
   
private:
   sf::Vector2i cord;
   int direction{0};
   bool alive{true};
   int animation_it{0};


};
#endif
