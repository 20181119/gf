#include "enemy.h"
// 선규 열심히 하는구나. 끝까지 포기하지 말고 하렴..

enemy::enemy(const loadParams*  pParams):SDLgameobject(pParams){}


void enemy::draw()
{
   SDLgameobject::draw();
}

void enemy::update()
{
   m_currentframe=((SDL_GetTicks()/100)%8);
}

void enemy::clean()
{
  
}