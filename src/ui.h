#pragma once
#include "types.h"

class UI{
  public:
  virtual void Plot(const Edge&) = 0;
  virtual void Plot(const Vertex&) = 0;
};

