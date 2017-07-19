#include "Chart.h"
#include <exception>
#include <iostream>

using namespace std;
Chart::Chart()
   : pellets_map{}, points_map{}, fruits_map{}, list{}, pacman(&list), text{}
{}

void Chart::init()
{
   cout << "Loading texture...\n";
   if (!text.loadFromFile("texture/spritesheet.jpg")) throw logic_error("Texture missing \n");
   cout << "Initialize sprites... ";
   for ( auto & item : list)
   {
      item->setSprite(text);
      cout << item->name << " , ";
   }
   cout << "\b\b  \n";
   cout << "Creating map...\n";
   
   cout << "Setting player position...\n";
   pacman.setPos(400,400);
}

void Chart::update()
{
   // pacman.setKeys(Keymanager::getKey());

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
