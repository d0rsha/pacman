#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <list>

#define SPRITE_SIZE_X 16
#define SPRITE_SIZE_Y 16

typedef std::pair<int, int> Coordinate;

class Entity
{
public:
   Entity(std::List<Entity*> list, sf::Vector2f cord)
      :rect{sf::Vector2f(SPRITE_SIZE_X, SPRITE_SIZE_Y)}, sprite{text}
      {
         sprite.setTextureRect{sf::Vector2f{SPRITE_SIZE_X, SPRITE_SIZE_Y}};
         sprite.setPosition{cord};
      }

protected:
   sf::RectangleShape rect;
   sf::Sprite sprite;
private:
   static sf::Texture text{"texture/spritesheet.jpg"};
};

#endif
