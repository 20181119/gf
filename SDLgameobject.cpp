#include "SDLgameobject.h"
#include "loadParams.h"
#include "texturemanager.h"
#include "game.h"

SDLgameobject::SDLgameobject(const loadParams*  pParams):gameobject(pParams), m_position(pParams->getX(), pParams->getY()),
m_velocity(0,0), m_accel(0,0)
{
  m_width=pParams->getwidth();
  m_height=pParams->getheight();
  m_textureID=pParams->gettextureID();

  m_currentrow=0;
  m_currentframe=0;
  
}
void SDLgameobject::update()
{
  m_velocity += m_accel;
  m_position += m_velocity;
}

void SDLgameobject::draw()
{
   texturemanager::instance()->drawframe(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentrow, m_currentframe, game::getinstance()->getRenderer());
}

