#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <list>

#define SPRITE_SIZE_X 16
#define SPRITE_SIZE_Y 16


class Entity
{
public:
   virtual ~Entity() {}
   Entity(std::list<Entity*>* list, sf::Vector2f cord, sf::Vector2i size)
      :rect{sf::Vector2f(SPRITE_SIZE_X, SPRITE_SIZE_Y)}, sprite{}
      {
         sprite.setPosition(cord);
         sprite.setTextureRect(sf::IntRect{sf::Vector2i(0, 0), size});
         list->push_back(this);
         rect.setFillColor(sf::Color::Red);
      }
   void draw(sf::RenderWindow* window)
      {
         window->draw(sprite);
         window->draw(rect);
      }
   void setSprite(sf::Texture text)
      {
         sprite.setTexture(text);
      }
   sf::Vector2f getPosition()
   /** return center of circle **/
      {
         return sf::Vector2f(rect.getPosition().x + rect.getGlobalBounds().width/2, 
                             rect.getPosition().y + rect.getGlobalBounds().width/2);
      }
   virtual void update()
      {}

protected:
   sf::RectangleShape rect;
   sf::Sprite sprite;
private:
};

#endif
