#pragma once
#include "ui.h"
#include <opencv2/imgproc/imgproc.hpp>

class UIOpenCV: public UI{
  public:
  UIOpenCV();
  void Plot(const Edge&) override;
  void Plot(const Vertex&)  override;
  private:
  cv::Mat mat;
  void Repaint();
};
