#pragma once
#include "gameobject.h"
#include "SDLgameobject.h"
#include "loadParams.h"


class player : public SDLgameobject
{
public:
  player(const loadParams*  pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
};