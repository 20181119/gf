#include "game.h"
#include "SDL_image.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"
#include "enemy.h"
#include "loadParams.h"


game* game::instance=0;

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
  m_gameoj.push_back(new player(new loadParams(100,100,128,128,"alien_run")));
  m_gameoj.push_back(new enemy(new loadParams(100,100,128,128,"alien_run")));


  


  m_bRunning=true;
  return true;
}


void game::update()
{
  m_go.update();
  m_p.update();
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
  for(int i=0;i !=m_gameoj.size();i++)
  {
    m_gameoj[i]->draw();
  }
  SDL_RenderPresent(m_pRenderer);
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