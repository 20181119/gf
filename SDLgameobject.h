#pragma once
#include "gameobject.h"
#include "loadParams.h"

class SDLgameobject:public gameobject
{
  public:
    SDLgameobject(const loadParams*  pParams);
    virtual void draw();
    virtual void update(){}
    virtual void clean(){}
    virtual ~SDLgameobject(){}
  
  protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_currentrow;
    int m_currentframe;
    string m_textureID;

};