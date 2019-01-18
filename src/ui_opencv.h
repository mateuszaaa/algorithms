#pragma once
#include <opencv2/imgproc/imgproc.hpp>
#include "edge.h"
#include "vertex.h"

enum class Color{
  Red,
  Green,
  Blue,
};

enum class Thickness: std::uint16_t{
  Slim=1,
  Normal=2,
  Thick=3,
};

class UIOpenCV{
  public:
  UIOpenCV();
  void Plot(Edge, Color c=Color::Green, Thickness t=Thickness::Normal);
  void Plot(Vertex, Color c=Color::Green, Thickness t=Thickness::Normal);
  void Update();
  private:
  cv::Mat mat;
};
