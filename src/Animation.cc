#include "Animation.h"
#include <iostream>
#include <exception>
Animation::Animation(std::list<Entity*>* list, sf::IntRect textureBox)
   :Entity{list, textureBox, sf::Vector2i(SPRITE_SIZE_X, SPRITE_SIZE_Y), "pacman"}, sheetCoordinate{textureBox.left, textureBox.top}, animation_it_limit{}
{
   setSprite(textureBox);
}
void Animation::update()
{ 
//Update movement 
   Entity::rect.move(direction);

// Set sprite
   Entity::sprite.setPosition(Entity::rect.getPosition());
   counter++;
   if (counter > 5) 
   {
      counter = 0;
      // Set new coordinate for sheetCoordinate
      if (horizontal)
      {
         Entity::sprite.setTextureRect(sf::IntRect(sheetCoordinate + sf::Vector2i(Entity::size.x + Entity::sprite.getTextureRect().left, 0), Entity::size));
      }
      else
      {
         Entity::sprite.setTextureRect(sf::IntRect(sheetCoordinate + sf::Vector2i(0, Entity::size.y + Entity::sprite.getTextureRect().top), Entity::size));
      }

      if (Entity::sprite.getTextureRect().left > (sheetCoordinate.x + Entity::size.x * animation_it_limit) ||
          Entity::sprite.getTextureRect().top > (sheetCoordinate.y + Entity::size.y * animation_it_limit))
      {
         Entity::sprite.setTextureRect(sf::IntRect(sheetCoordinate, Entity::size));
      }
   }
}

void Animation::setSprite(sf::IntRect textureBox)
{
   sheetCoordinate = sf::Vector2i(textureBox.left, textureBox.top);
   if (textureBox.width  > Entity::size.x)
   {
      animation_it_limit = textureBox.width/Entity::size.x +1; 
      horizontal = true;
   }
   else if (textureBox.height > Entity::size.y)
   {
      animation_it_limit = textureBox.height/Entity::size.y;
      horizontal = false;
   }
   else
      throw std::logic_error("Animation bouinding box must contain multiply sprites, setSprite(sf::IntRect )\n");
   
   
   Entity::sprite.setTextureRect(sf::IntRect{sheetCoordinate, Entity::size});
}
