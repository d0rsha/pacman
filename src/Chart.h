#ifndef CHART_H
#define CHART_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <map>
#include <list>

class Chart
{
public:
   Chart();
   void init();
private:
   std::map<sf::Vector2i, bool> pellets_map;
   std::map<sf::Vector2i, bool> points_map;
   std::map<sf::Vector2i, bool> fruits_map;
   std::list<Entity> list;
};

#endif
