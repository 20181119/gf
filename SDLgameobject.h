#pragma once
#include "gameobject.h"
#include "loadParams.h"
#include "Vector2D.h"



class SDLgameobject:public gameobject
{
  public:
    SDLgameobject(const loadParams*  pParams);
    virtual void draw();
    virtual void update();
    virtual void clean(){}
    virtual ~SDLgameobject(){}
  
  protected:
    Vector2D m_position;
    int m_width;
    int m_height;
    int m_currentrow;
    int m_currentframe;
    string m_textureID;

};