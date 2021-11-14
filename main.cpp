#include "game.h"
#include "texturemanager.h"
#include <iostream>
#include "InputHandler.h"
game* g_game=0;
const int FPS=60;
const int DELAY_TIME=1000.0f/FPS;

int main(int argc, char* args[])
{
 if(game::getinstance()->init("game framework",100,100,600,480,0))
 {
   Uint32 framestart, frametime;
  while(game::getinstance()->running())
  {
    game::getinstance()->handleEvents();
    game::getinstance()->update();
    game::getinstance()->render();
    frametime=SDL_GetTicks()-framestart;

    if(frametime<DELAY_TIME)
     {
       SDL_Delay((int)(DELAY_TIME-frametime));
     }
  }
 }
 else
 {
   std::cout<<"game init failure"<<SDL_GetError()<<endl;
   return -1;
 }
  game::getinstance()->clean();
  InputHandler::Instance()->clean();
  return 0;
}