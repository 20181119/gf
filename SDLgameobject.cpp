#include "SDLgameobject.h"
#include "loadParams.h"
#include "texturemanager.h"
#include "game.h"

SDLgameobject::SDLgameobject(const loadParams*  pParams):gameobject(pParams)
{
  m_x=pParams->getX();
  m_y=pParams->getY();
  m_width=pParams->getwidth();
  m_height=pParams->getheight();
  m_textureID=pParams->gettextureID();

  m_currentrow=0;
  m_currentframe=0;
  
}
void SDLgameobject::draw()
{
   texturemanager::instance()->drawframe(m_textureID, m_x, m_y, m_width, m_height, m_currentrow, m_currentframe, game::getinstance()->getRenderer());
}

