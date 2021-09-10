#include <iostream>
#include <SDL.h>
#include <string.h>
using namespace std;

SDL_Window* g_pWindow=0;
SDL_Renderer* g_pRenderer=0;
bool g_bRunning=false;

bool Init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
  {
    g_pWindow=SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if(g_pWindow!=0)
    {
      g_pRenderer=SDL_CreateRenderer(g_pWindow,-1,0);
    }
    
  }
  else
  {
    return false;
  }
  SDL_SetRenderDrawColor(g_pRenderer,0,0,100,255);
  return true;
}




void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}



int main(int argc, char* args[])
{

  bool counter=false;
  string input;
  while(counter==false)
  {
  cout<<"if you want to launch program, please input[start]: ";
  cin>>input;//특정코드를 입력해야만 창이 실행됨 
  if(input=="start")//입력 성공시 
  counter=true;//실행
  else//입력 실패시
  cout<<"invaild code."<<endl;//오류 메시지 출력 후
  continue;//재입력
  }

  while(counter==true)
  {
      if(Init("Game Framework",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN))
     {
        g_bRunning=true;
     }
     else
     {
       return 1;
     }
     while(g_bRunning)
     {
       render();
        SDL_Delay(5000);
        SDL_Quit();
        break;
     }
    break;
  }

  return 0;
}