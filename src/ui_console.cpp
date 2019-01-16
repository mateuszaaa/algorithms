#include "ui_console.h"
#include <iostream>

void UiConsole::Plot(const Edge& e) {
    Vertex from,to;
    std::tie(from,to) = e;
    int x1,y1,x2,y2;
    std::tie(x1,y1) = from;
    std::tie(x2,y2) = to;
    std::cout << "Edge (" << x1 << ", " << y1 << ")  <-> (" << x2 << ", " << y2 << ")" << std::endl;
}

void UiConsole::Plot(const Vertex& v){
  int x,y;
  std::tie(x,y) = v;
  std::cout << "Vertex (" << x << ", " << y << ")" << std::endl;
}
