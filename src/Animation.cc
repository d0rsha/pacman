#include "Animation.h"
#include <iostream>

Animation::Animation(std::list<Entity*>* list, sf::Vector2i sheetCoord, int ani_it_limit)
   :Entity{list, sf::Vector2f(0,0), sf::Vector2i(SPRITE_SIZE_X, SPRITE_SIZE_Y), "pacman"}, sheetCoordinate{sheetCoord}, animation_it_limit{ani_it_limit}
{}
void Animation::update()
{ 
//Update movement 
   Entity::rect.move(direction);
   //std::cout << direction.x << " , " << direction.y << std::endl;
// Set sprite
   Entity::sprite.setPosition(Entity::rect.getPosition());
   counter++;
   if (counter > 5) 
   {
      counter = 0;
      // Set new coordinate for sheetCoordinate
      sheetCoordinate.x += sprite.getGlobalBounds().width;
      if (sheetCoordinate.x > 5 + sprite.getGlobalBounds().width * animation_it_limit)
         sheetCoordinate.x = 4;
      // Set textureRect
      Entity::sprite.setTextureRect(sf::IntRect(sf::Vector2i(sheetCoordinate.x, sheetCoordinate.y), sf::Vector2i(Entity::rect.getSize().x, Entity::rect.getSize().y)));
   }
}
