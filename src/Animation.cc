#include "Animation.h"

Animation::Animation(std::list<Entity*>* list, sf::Vector2i pos)
   :Entity{list, sf::Vector2f(0,0), sf::Vector2i(16, 16)}, cord{pos}
{}
void Animation::update()
{ 
   Entity::sprite.setPosition(Entity::rect.getPosition());
}
