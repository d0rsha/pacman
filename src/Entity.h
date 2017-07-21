#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include <iostream>

// Sprite size
#define SPRITE_SIZE_X 20
#define SPRITE_SIZE_Y 20

// Movement speed
#define PACMAN_SPEED 1
#define BOT_SPEED 1

class Entity
{
public:
   virtual ~Entity() {}
   Entity(std::list<Entity*>* list,  sf::IntRect textureBox, sf::Vector2i s = sf::Vector2i(SPRITE_SIZE_X, SPRITE_SIZE_Y), std::string name = "UNDEFINED")
      :name{name}, rect{sf::Vector2f((textureBox.width - textureBox.left)/s.x, 
                                     (textureBox.height - textureBox.top)/s.y)}, sprite{}, size{s}
      {
         sprite.setTextureRect(sf::IntRect{textureBox.left, textureBox.top, s.x, s.y});
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
   void setPosition(sf::Vector2f pos)
      {
         rect.setPosition(pos);
      }
   virtual void update()
      {}

   std::string name;
protected:
   sf::RectangleShape rect;
   sf::Sprite sprite;
   sf::Vector2i size;
private:
   
};

#endif
