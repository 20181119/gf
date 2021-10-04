#ifndef _game_
#define _game_
#include "SDL.h"
#include "texturemanager.h"


class game
{
   public:
     game() {}
     ~game() {}

     
     int m_currentframe;

   bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
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