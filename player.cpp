#include "player.h"
#include "InputHandler.h"
#include <iostream>
player::player(const loadParams*  pParams):SDLgameobject(pParams){}


void player::draw()
{
   SDLgameobject::draw();
}

void player::update()
{
   handleInput();
   SDLgameobject::update();
   m_currentframe=((SDL_GetTicks()/100)%8);
}

void player::handleInput()
{
  if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
     {
        m_velocity.setX(2);
     }
  else if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
     {
        m_velocity.setX(-2);
     }
  else if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
     {
        m_velocity.setY(-2);
     }
  else if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
     {
        m_velocity.setY(2);
     }
  else
     {
        m_velocity.setX(0);
        m_velocity.setY(0);
     }

}

void player::clean()
{
  
}
