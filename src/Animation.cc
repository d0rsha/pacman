#include "Animation.h"

Animation::Animation(std::list<Entity*>* list, sf::Vector2i sheetCoord, int ani_it_limit)
   :Entity{list, sf::Vector2f(0,0), sf::Vector2i(16, 16)}, sheetCoordinate{sheetCoord}, animation_it_limit{ani_it_limit}
{}
void Animation::update()
{ 
//Update movement 
   Entity::rect.move(direction);

// Set sprite
   Entity::sprite.setPosition(Entity::rect.getPosition());
   counter++;
   if (counter > 20) 
   {
      // Set new coordinate for sheetCoordinate
      sheetCoordinate.x += sprite.getGlobalBounds().width;
      if (sheetCoordinate.x > sprite.getGlobalBounds().width * animation_it_limit)
         sheetCoordinate.x = 0;
      // Set textureRect
      Entity::sprite.setTextureRect(sf::IntRect(sf::Vector2i(sheetCoordinate.x, sheetCoordinate.y), sf::Vector2i(Entity::rect.getSize().x, Entity::rect.getSize().y)));
   }
}
