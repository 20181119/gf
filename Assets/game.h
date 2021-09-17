#ifndef _game_
#define _game_
#include "SDL.h"

class game
{
   public:
     game() {}
     ~game() {}

   bool init();
   void render();
   void update();
   bool running();
   void handleEvents();
   void clean();

   private:
     SDL_Window* m_pWindow;
     SDL_Renderer* m_pRenderer;
     bool m_bRunning;
};
#endif