#pragma once
#include "ui.h"

class UIOpenCV: public UI{
  public:
  void PlotEdge(const Edge& e) override;
  void PlotVertex(const Vertex&)  override;
};
