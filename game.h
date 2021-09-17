#ifndef _game_
#define _game_
#include "SDL.h"

class game
{
   public:
     game() {}
     ~game() {}

   bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
   void render();
   void update();
   bool running();
   void handleEvents();
   void clean();

   private:
     SDL_Texture* m_pTexture;
     SDL_Rect m_sourceRectangle;
     SDL_Rect m_destinationRectangle;
     SDL_Window* m_pWindow;
     SDL_Renderer* m_pRenderer;
     bool m_bRunning;
};
#endif