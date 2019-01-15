#include <iostream>
#include <memory>

#include "ui.h"
#include "ui_console.h"
#include "types.h"

int main(){
  auto ui = std::make_unique<UiConsole>();
  Vertex v{1,2};
  Edge e{ {1,2}, {3,4} };
  ui->PlotEdge(e);
  ui->PlotVertex(v);
}
