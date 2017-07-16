#ifndef CHART_H
#define CHART_H

#include <SFML/Graphics.hpp>
#include <map>

class Chart
{
public:
   Chart();

private:
   std::map<sf::Vector2i, bool> pellets_map;
   std::map<sf::Vector2i, bool> points_map;
   std::map<sf::Vector2i, bool> fruits_map;

};

#endif
