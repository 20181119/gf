#pragma once
#include "gameobject.h"


class player : public gameobject
{
public:
  void load(int x, int y, int width, int height,  string textureID);
  void draw(SDL_Renderer* pRenderer);
  
  void update() {}
  void clean() {}
};