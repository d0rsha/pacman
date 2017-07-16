#include "Chart.h"
#include <exception>

using namespace std;
Chart::Chart()
{}

void Chart::init()
{
   sf::Texture text;
   if (!text.loadFromFile("texture/spritesheet.jpg")) throw logic_error("Texture missing \n");
   for ( auto & item : list)
   {
      item.setSprite(text);
   }
}
