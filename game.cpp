#include "game.h"
#include "SDL_image.h"
#include "texturemanager.h"

float alienX=0;
float alienY=100;




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

 if(!texturemanager::instance()->load("Assets/New Piskel.png","alien_run",m_pRenderer))//캐릭터이미지아이디설정
  {
    return false;
  }

  if(!texturemanager::instance()->landscapeload("Assets/배경연습1111.png","landscape",m_pRenderer))//배경이미지아이디설정
  {
    return false;
  }


  m_bRunning=true;
  return true;
}

void game::update()
{
  m_currentframe=((SDL_GetTicks()/100) % 8);

     alienX+=0.5;
  if(alienX==540)
    
  
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
  texturemanager::instance()->landscapedraw("landscape",0, 0, 640, 640, m_pRenderer);//배경이미지표시
  texturemanager::instance()->drawframe("alien_run",alienX, alienY, 128, 128, 0,m_currentframe, m_pRenderer);//캐릭터애니메이션이미지표시
  
 
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