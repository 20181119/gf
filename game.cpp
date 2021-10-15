#include "game.h"
#include "SDL_image.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"




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

  gameobject* m_go=new gameobject();
  gameobject* m_p=new player();

  m_go->load(100,100,128,128,"alien_run");
  m_p->load(300,300,128,128,"alien_run");
  m_gameoj.push_back(m_go);
  m_gameoj.push_back(m_p);


  m_bRunning=true;
  return true;
}

void game::update()
{
for(int i=0;i<m_gameoj.size();i++)
  {
    m_gameoj[i]->update();
  }
}

void game::render()
{
  SDL_RenderClear(m_pRenderer);  // 김현도 실습조교에게 문의해봐다오. 나는 이제 회의가 있어서... lms에서 메시지 보내기로.. 
// 이전에 그리는 코드는 다 삭제 했니? 
//텍스쳐메니저헤더에 싱글톤 구현되어있습니다
  for(int i=0;i<m_gameoj.size();i++)
  {
    m_gameoj[i]->draw(m_pRenderer);
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