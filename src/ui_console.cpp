#include "ui_console.h"
#include <iostream>

void UiConsole::PlotEdge(const Edge& e) {
    auto [from,to] = e;
    auto [x1, y1] = from;
    auto [x2, y2] = to;
    std::cout << "Edge (" << x1 << ", " << y1 << ")  <-> (" << x2 << ", " << y2 << ")" << std::endl;
}

void UiConsole::PlotVertex(const Vertex& v){
    auto [x, y] = v;
    std::cout << "Vertex (" << x << ", " << y << ")" << std::endl;
}
