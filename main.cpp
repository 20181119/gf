#include "game.h"
#include "texturemanager.h"
game* g_game=0;

int main(int argc, char* args[])
{
  g_game=new game();
  g_game->init("game framework",100,100,600,480,0);
  while(g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);
  }
  g_game->clean();
  return 0;
}