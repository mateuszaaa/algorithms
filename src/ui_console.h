#include "ui.h"

class UiConsole: public UI{
  public:
  void Plot(const Edge& e) override;
  void Plot(const Vertex&)  override;
};
