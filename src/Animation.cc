#include "Animation.h"
#include <iostream>
#include <exception>

using namespace std;

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
      moveTextureRect();
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
   
   ani_counter = 1;
   Entity::sprite.setTextureRect(sf::IntRect{sheetCoordinate, Entity::size});
}

void Animation::moveTextureRect()
{
     // Set new coordinate for sheetCoordinate
   switch ((int)horizontal) {
      case true: Entity::sprite.setTextureRect(sf::IntRect(sheetCoordinate + sf::Vector2i(Entity::size.x * ani_counter, sheetCoordinate.y  ), Entity::size));
      case false: Entity::sprite.setTextureRect(sf::IntRect(sheetCoordinate + sf::Vector2i(sheetCoordinate.x , Entity::size.y * ani_counter), Entity::size));
      }

      if (ani_counter >= animation_it_limit)
      {
         switch ((int)horizontal){
         case true: setSprite(sf::IntRect(sheetCoordinate, sf::Vector2i(Entity::size.x * animation_it_limit, Entity::size.y)));
         case false: setSprite(sf::IntRect(sheetCoordinate, sf::Vector2i(Entity::size.x, Entity::size.y * animation_it_limit)));               
         }
      }
      cout << ani_counter << endl;
      ani_counter++;
}
