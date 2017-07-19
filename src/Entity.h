#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include <iostream>

#define SPRITE_SIZE_X 20
#define SPRITE_SIZE_Y 20


class Entity
{
public:
   virtual ~Entity() {}
   Entity(std::list<Entity*>* list, sf::Vector2f cord, sf::Vector2i size, std::string name = "UNDEFINED")
      :name{name}, rect{sf::Vector2f(size.x+1, size.y+1)}, sprite{}
      {
         sprite.setPosition(cord);
         sprite.setTextureRect(sf::IntRect{sf::Vector2i(5, 0), size});
         list->push_back(this);
         rect.setFillColor(sf::Color::Red);
      }
   void draw(sf::RenderWindow* window)
      {
         window->draw(rect);
         window->draw(sprite);
      }
   void setSprite(sf::Texture const & text)
      {
         sprite.setTexture(text);
      }
   sf::Vector2f getPosition() const
   /** return center of circle **/
      {
         return sf::Vector2f(rect.getPosition().x + rect.getGlobalBounds().width/2, 
                             rect.getPosition().y + rect.getGlobalBounds().width/2);
      }
   virtual void update()
      {}

   std::string name;
protected:
   sf::RectangleShape rect;
   sf::Sprite sprite;
private:
   
};

#endif
