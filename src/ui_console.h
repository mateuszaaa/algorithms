#include "ui.h"

class UiConsole: public UI{
  public:
  void PlotEdge(const Edge& e) override;
  void PlotVertex(const Vertex&)  override;
};
