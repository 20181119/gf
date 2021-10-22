#pragma once
#include "gameobject.h"
#include "loadParams.h"
#include "SDLgameobject.h"


class enemy : public SDLgameobject
{
public:
  enemy(const loadParams*  pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};