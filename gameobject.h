#pragma once
#include "SDL.h"
#include<string>
#include "loadParams.h"
using namespace std;

class gameobject
{
  public:
  virtual void draw()=0;
  virtual void update()=0;
  virtual void clean()=0;
  virtual ~gameobject(){}

  protected:
    gameobject(const loadParams* pParams){}
}

