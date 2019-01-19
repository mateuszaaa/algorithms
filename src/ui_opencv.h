#pragma once
#include <opencv2/imgproc/imgproc.hpp>
#include "edge.h"
#include "graph.h"
#include "vertex.h"

enum class Color{
  Red,
  Green,
  Blue,
};

enum class Thickness: std::uint16_t{
  Slim=1,
  Medium=2,
  Thick=3,
};

class UIOpenCV{
  public:
  UIOpenCV();
  void Plot(Edge, Color c=Color::Green, Thickness t=Thickness::Medium);
  void Plot(Vertex, Color c=Color::Green, Thickness t=Thickness::Medium);
  void Plot(const Graph &);
  void Update();
  private:
  cv::Mat mat;

  void Plot(const Edges&, Color c=Color::Green, Thickness t=Thickness::Medium);
  void Plot(const Vertexes&, Color c=Color::Green, Thickness t=Thickness::Medium);
};
