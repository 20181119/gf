#include "game.h"

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

  SDL_Surface* pTempSurface=SDL_LoadBMP("Assets/배경연습1.bmp");
  m_pTexture=SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  SDL_QueryTexture(m_pTexture, NULL,NULL,&m_sourceRectangle.w,&m_sourceRectangle.h);

  m_destinationRectangle.w=600;
  m_destinationRectangle.h=480;

  m_destinationRectangle.x=m_sourceRectangle.x=0;
  m_destinationRectangle.y=m_sourceRectangle.y=0;

  


  SDL_Surface* pTempSurface1=SDL_LoadBMP("Assets/고양이어폰.bmp");
  m_pTexture1=SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface1);
  SDL_FreeSurface(pTempSurface1);

  SDL_QueryTexture(m_pTexture1, NULL,NULL,&m_sourceRectangle1.w,&m_sourceRectangle1.h);

  m_destinationRectangle1.w=100;
  m_destinationRectangle1.h=100;

  m_destinationRectangle1.x=m_sourceRectangle1.x=0;
  m_destinationRectangle1.y=m_sourceRectangle1.y=100;
  

  m_bRunning=true;
  return true;
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderCopy(m_pRenderer, m_pTexture1, &m_sourceRectangle1, &m_destinationRectangle1);
  
  SDL_DestroyTexture(m_pTexture1);
  SDL_RenderPresent(m_pRenderer);
}

void game::update()
{
  
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