#include "texturemanager.h"
#include "SDL_image.h"

texturemanager* texturemanager::s_pinstance=0;


bool texturemanager::load(string filename, string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface=IMG_Load(filename.c_str());
  if(pTempSurface==0)
  {
    return false;
  }
  
  SDL_Texture* pTexture=SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if(pTexture!=0)
  {
    m_Texturemap[id]=pTexture;
    return true;
  }
  return false;
}//캐릭터이미지생성

 bool texturemanager::landscapeload(string filename, string id, SDL_Renderer* pRenderer)

{
  SDL_Surface* pTempSurface=IMG_Load(filename.c_str());
  if(pTempSurface==0)
  {
    return false;
  }
  
  SDL_Texture* pTexture=SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if(pTexture!=0)
  {
    m_landscapeTexturemap[id]=pTexture;
    return true;
  }
  return false;
}//배경이미지생성








void texturemanager::landscapedraw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x=0;
  srcRect.y=0;

  srcRect.w=desRect.w=width;
  srcRect.h=desRect.h=height;
  desRect.x=x;
  desRect.y=y;

  SDL_RenderCopyEx(pRenderer, m_landscapeTexturemap[id], &srcRect, &desRect, 0, 0, flip);
}//배경이미지드로우

void texturemanager::drawframe(string id, int x, int y, int width, int height, int currentrow, int currentframe, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x=width*currentframe;
  srcRect.y=height*currentrow;
  srcRect.w=desRect.w=width;
  srcRect.h=desRect.h=height;
  desRect.x=x;
  desRect.y=y;

  int r=0;
  
  SDL_RenderCopyEx(pRenderer, m_Texturemap[id], &srcRect, &desRect, r, 0, flip);

}//캐릭터애니메이션이미지드로우
