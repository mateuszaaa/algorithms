#include "ui_opencv.h"
#include <opencv2/highgui/highgui.hpp>

namespace {
cv::Scalar ToCvColor(Color c) {
  switch (c) {
    case Color::Blue:
      return {255, 0, 0};
    case Color::Red:
      return {0, 0, 255};
    case Color::Green:
      return {0, 255, 0};
    default: { throw std::runtime_error("cannot convert color to cv::Scalar"); }
  }
}

template <typename T>
constexpr auto ToUnderlying(T e) noexcept {
  return static_cast<std::underlying_type_t<T>>(e);
}

Edge toEdge(std::vector<Vertex> vertexes, Connection c) {
  return {vertexes[std::get<0>(c)], vertexes[std::get<1>(c)]};
}
}  // namespace

UIOpenCV::UIOpenCV(): mat(500,500, CV_8UC3, {255,255,255}){
  Update();
}

void UIOpenCV::Plot(Edge e, Color c, Thickness t){
  Vertex from,to;
  std::tie(from,to) = e;
  int x1,y1,x2,y2;
  std::tie(x1,y1) = from;
  std::tie(x2,y2) = to;
  cv::line(mat, {x1,y1}, {x2,y2}, ToCvColor(c), ToUnderlying(t));
}

void UIOpenCV::Plot(const Edges &edges, Color c, Thickness t){
  for(auto e: edges){
    Plot(e, c ,t);
  }
}

void UIOpenCV::Plot(Vertex v, Color c, Thickness t){
  int x,y;
  std::tie(x,y) = v;
  cv::circle(mat, {x,y}, 5, ToCvColor(c) ,ToUnderlying(t));
}

void UIOpenCV::Plot(const Vertexes &vertexes, Color c, Thickness t){
  for(auto v: vertexes){
    Plot(v, c ,t);
  }
}

void UIOpenCV::Plot(const Graph &g){
  Edges edges;
  std::transform(std::begin(g.connections), std::end(g.connections), std::back_inserter(edges),
      [&g](auto conn){
        return toEdge(g.vertexes, conn);
      }
  );
  Plot(edges, Color::Green, Thickness::Slim);
  Plot(g.vertexes, Color::Red, Thickness::Medium);
}

void UIOpenCV::Update(){
  cv::imshow("graph", mat);
}
