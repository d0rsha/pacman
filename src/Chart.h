#ifndef CHART_H
#define CHART_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include "Pacman.h"
#include "Keymanager.h"

#include <map>
#include <list>

class Chart
{
public:
   Chart();
   void init();
   void update();
   void draw(sf::RenderWindow* window);
private:
   std::map<sf::Vector2i, bool> pellets_map;
   std::map<sf::Vector2i, bool> points_map;
   std::map<sf::Vector2i, bool> fruits_map;
   std::list<Entity*> list;
   Pacman pacman;
   sf::Texture text;
};

#endif
