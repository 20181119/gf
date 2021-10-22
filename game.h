#ifndef _game_
#define _game_
#include "SDL.h"
#include "texturemanager.h"
#include "gameobject.h"
#include "player.h"

class game
{
  private:
     game() {}
     static game* instance;

   public:
     
     ~game() {}

     
     static game* getinstance()
     {
       if(instance==0)
       instance=new game();
       return instance;
     }
     

   bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
   void render();
   bool running();
   void handleEvents();
   void update();
   void clean();
  
  gameobject m_go;
  player m_p;
  

   private:
     SDL_Window* m_pWindow;
     SDL_Renderer* m_pRenderer;
     bool m_bRunning;
};
#endif