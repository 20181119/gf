#include "player.h"
// 선규 열심히 하는구나. 끝까지 포기하지 말고 하렴..

player::player(const loadParams*  pParams):SDLgameobject(pParams){}


void player::draw()
{
   gameobject::draw();
}

void player::update()
{
   m_x+=1;
   m_currentframe=((SDL_GetTicks()/100)%8);
}

void player::clean()
{
  
}
