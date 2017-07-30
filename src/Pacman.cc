#include "Pacman.h"

using namespace std;

Pacman::Pacman(list<Entity*>* list)
   :Animation(list, sf::IntRect(4, 64, 20, 60))
{
   Animation::Entity::rect.setFillColor(sf::Color::Magenta);
}

void Pacman::update()
{
   setKeys();
   Animation::update();
}

void Pacman::setKeys()
{
   // Add collision check! If path not possible do not change dir
   if (Keymanager::getKey() == sf::Keyboard::Key::Right &&
       direction != sf::Vector2f(1,0))
   {
      Animation::direction = sf::Vector2f(1, 0);
      Animation::setSprite(sf::IntRect(4, 24, 60, 20));
   }
   else if (Keymanager::getKey() == sf::Keyboard::Key::Up &&
       direction != sf::Vector2f(0, -1))
   {
      Animation::direction = sf::Vector2f(0, -1);
      Animation::setSprite(sf::IntRect(4, 44, 60, 20));
   }
   else if (Keymanager::getKey() == sf::Keyboard::Key::Left &&
       direction != sf::Vector2f(-1, 0))
   {
      Animation::direction = sf::Vector2f(-1, 0);
      Animation::setSprite(sf::IntRect( 4, 4, 60, 20));
   }
   else if (Keymanager::getKey() == sf::Keyboard::Key::Down &&
       direction != sf::Vector2f(0, 1))
   {
      Animation::direction = sf::Vector2f(0, 1);
      Animation::setSprite(sf::IntRect(4, 64, 60, 20));
   }
   /*else if (Not movable) stay at point
   {
      Animation::direction = sf::Vector2f(0, 0);
      Animation::setSprite(sf::IntRect(44, 4, 20, 80));
      }*/
}

void Pacman::setPos(int x, int y)
{
   Animation::Entity::setPosition(sf::Vector2f(x,y));
}
