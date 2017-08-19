#ifndef CHART_H
#define CHART_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include "Pacman.h"
#include "Keymanager.h"
#include "Powerup.h"

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
   std::map<sf::Vector2f, Powerup> powerup_map;
   
   std::vector<sf::Vector2f> wall_vector_cord;
   

   std::list<Entity*> list;
   Pacman pacman;
   sf::Texture text;
};

#endif
