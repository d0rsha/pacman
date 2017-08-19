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
   virtual ~Animation() {
   Animation(std::list<Entity*>* list, sf::IntRect textureBox);
   virtual void update() override;
protected:
   sf::Vector2f direction{0, 0};
   void setSprite(sf::IntRect textureBox);
private:
   void moveTextureRect();
   sf::Vector2i sheetCoordinate; // Coordinate on spritesheet
   bool alive{true};
   int animation_it_limit; //Max animation iterations
   bool horizontal{true};
   int counter{};
   int ani_counter{};

};
#endif
