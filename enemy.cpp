#include "enemy.h"
#include <iostream>
#include "InputHandler.h"
enemy::enemy(const loadParams*  pParams):SDLgameobject(pParams){}


void enemy::draw()
{
   SDLgameobject::draw();
}

void enemy::update()
{
   handleInput();
   m_currentframe=((SDL_GetTicks()/100)%8);
   
}

void enemy::clean()
{
  
}

void enemy::handleInput()
{
  if(InputHandler::Instance()->getMouseButtonState(LEFT))
    {
       std::cout<<"shoot"<<endl;
    }
   Vector2D* vec=InputHandler::Instance()->getMousePosition();
   m_velocity=(*vec-m_position)/100;
}