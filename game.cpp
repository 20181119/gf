#include "game.h"
#include "SDL_image.h"
#include "texturemanager.h"


bool game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  

  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    m_pWindow=SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if(m_pWindow!=0)
    {
       m_pRenderer=SDL_CreateRenderer(m_pWindow,-1,0);
    
      if(m_pWindow!=0)
      {
         SDL_SetRenderDrawColor(m_pRenderer,0,0,100,255);
      }
      else
      {
       return false;
      }
    }
     else
      {
       return false;
      }
  }
  else
  {
    return false;
  }

 m_texturemanager.load("Assets/sonic.png","sonic_run",m_pRenderer);

  m_bRunning=true;
  return true;
}

void game::update()
{
  m_currentframe=((SDL_GetTicks()/100) % 8);
}

void game::render()
{
  m_texturemanager.draw("sonic_run",0, 0, 65, 65, m_pRenderer);
  m_texturemanager.drawframe("sonic_run",100, 100, 65, 65, 0,m_currentframe, m_pRenderer);
}

bool game::running()
{
  return m_bRunning;
}

void game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
       m_bRunning=false;
       break;
      default:
       break;
    }
  }
}

void game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}