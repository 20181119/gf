#include "texturemanager.h"
#include "SDL_image.h"



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
}

void texturemanager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect desRect;

  srcRect.x=0;
  srcRect.y=0;

  srcRect.w=desRect.w=width;
  srcRect.h=desRect.h=height;
  desRect.x=x;
  desRect.y=y;

  SDL_RenderCopyEx(pRenderer, m_Texturemap[id], &srcRect, &desRect, 0, 0, flip);
}

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

  SDL_RenderCopyEx(pRenderer, m_Texturemap[id], &srcRect, &desRect, 0, 0, flip);
}
