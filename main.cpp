#include "game.h"
#include "texturemanager.h"
#include <iostream>
game* g_game=0;

int main(int argc, char* args[])
{
 if(game::getinstance()->init("game framework",100,100,600,480,0))
 {
  while(game::getinstance()->running())
  {
    game::getinstance()->handleEvents();
    game::getinstance()->update();
    game::getinstance()->render();
    SDL_Delay(10);
  }

 }
 else

 {
   std::cout<<"game init failure"<<SDL_GetError()<<endl;
   return -1;
 }
  game::getinstance()->clean();
  return 0;
}