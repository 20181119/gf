#ifndef _game_
#define _game_
#include "SDL.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"
#include <vector>

class game
{
   public:
     game() {}
     ~game() {}

     
     

   bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
   void render();
   
   bool running();
   void handleEvents();
   void update();
   void clean();

   std::vector<gameobject*>m_gameoj;


   private:
     SDL_Window* m_pWindow;
     SDL_Renderer* m_pRenderer;
     bool m_bRunning;
};
#endif