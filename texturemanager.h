#ifndef _texturemanager_
#define _texturemanager_
#include "SDL.h"
#include "map"
#include <string>
using namespace std;


/*
class singleton
{
  private:
      singleton() {}
      
   public:
   static texturemanager instance()
   {
      if(s_pinstance==0)
       {
          s_pinstance= new texturemanager();
          return s_pinstance;
       }
   }
};
*/

class texturemanager
{
   private:
     texturemanager() {}
     static texturemanager* s_pinstance;

   public:
    
    ~texturemanager() {}

    


    static texturemanager* instance()
   {
      if(s_pinstance==0)
       {
          s_pinstance= new texturemanager();
          
       }
       return s_pinstance;
   }

   
    bool load(string filename, string id, SDL_Renderer* pRenderer);//캐릭터이미지생성

    void drawframe(string id, int x, int y, int width, int height, int currentrow, int currentframe, SDL_Renderer* pRenderer, SDL_RendererFlip flip=SDL_FLIP_NONE);
  private:
    map<string, SDL_Texture*> m_Texturemap;
};
#endif