#include "player.h"

void player::load(int x, int y, int width, int height,  string textureID)
{
   gameobject::load(x, y, width, height, textureID);
}


void player::draw(SDL_Renderer* pRenderer)
{
   gameobject::draw(pRenderer);
}


