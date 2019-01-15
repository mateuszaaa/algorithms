#pragma once
#include "types.h"

class UI{
  public:
  virtual void PlotEdge(const Edge&) = 0;
  virtual void PlotVertex(const Vertex&) = 0;
};

