#include "game.h"
#include "texturemanager.h"
game* g_game=0;


//다형성까지 구현했습니다. 스프라이트 출력문제는 고치치 못했고 이후에 수업이 있어 제출시간 준수를 위해 지금 제출합니다. 다음주 실습시간때 봐주시면 감사하겠습니다.

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