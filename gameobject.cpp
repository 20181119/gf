#include "gameobject.h"
#include "texturemanager.h"

void gameobject::load(int x, int y, int width, int height,  string textureID)
{
  int m_x = x;
  int m_y = y;
  int m_width = width;
  int m_height = height;
  
  m_textureID=textureID;
  m_currentframe = 0; // ((SDL_GetTicks()/100) % 8);
  m_currentrow = 0;
}
void gameobject::draw(SDL_Renderer* pRenderer)
{
  texturemanager::instance()->drawframe(m_textureID, m_x, m_y, m_width, m_height, m_currentrow, m_currentframe, pRenderer);
}
  
void gameobject::update()
{
   
}
void gameobject::clean()
{
  
}