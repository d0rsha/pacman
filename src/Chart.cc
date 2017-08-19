#include "Chart.h"
#include <exception>
#include <iostream>

using namespace std;
Chart::Chart()
   : powerup_map{}, wall_vector_cord{}, list{}, pacman(&list), text{}
{}

void Chart::init()
{
   cout << "Loading texture...\n";
   if (!text.loadFromFile("texture/spritesheet.png")) throw logic_error("Texture missing \n");
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
