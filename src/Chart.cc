#include "Chart.h"
#include <exception>
#include <iostream>

using namespace std;
Chart::Chart()
   : pellets_map{}, points_map{}, fruits_map{}, list{}, pacman(&list)
{}

void Chart::init()
{
   sf::Texture text;
   cout << "Loading texture...\n";
   if (!text.loadFromFile("texture/spritesheet.jpg")) throw logic_error("Texture missing \n");
   cout << "Initialize sprites...\n";
   for ( auto & item : list)
   {
      item->setSprite(text);
   }
   cout << "Creating map...\n";
   
   cout << "Setting player position...\n";
   pacman.setPos(100,100);

//Test
   list.push_back(new Entity{&list, sf::Vector2f(0, 64), sf::Vector2i(100, 100)});
}

void Chart::update()
{
   for ( auto & item : list )
   {
      item->update();
   }
}
void Chart::draw(sf::RenderWindow* window)
{
   for ( auto const & item : list)
   {
      item->draw(window);
   }
}
