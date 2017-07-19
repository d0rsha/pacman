#include "Pacman.h"

using namespace std;

Pacman::Pacman(list<Entity*>* list)
   :Animation(list, sf::Vector2i(0, 0), 2)
{

}

void Pacman::update()
{
   Animation::update();
}

void Pacman::setKeys(Keymanager key)
{
   if (key.getKey() == sf::Keyboard::Key::Right)
   {
      Animation::direction = sf::Vector2f(1,0);
   }
   if (key.getKey() == sf::Keyboard::Key::Up)
   {
      Animation::direction = sf::Vector2f(0,1);
   }
   if (key.getKey() == sf::Keyboard::Key::Left)
   {
      Animation::direction = sf::Vector2f(-1,0);
   }
   if (key.getKey() == sf::Keyboard::Key::Down)
   {
      Animation::direction = sf::Vector2f(0,-1);
   }
}

void Pacman::setPos(int x, int y)
{
   Animation::Entity::rect.setPosition(sf::Vector2f(x,y));
}
