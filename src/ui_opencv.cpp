#include "ui_opencv.h"
#include <opencv2/highgui/highgui.hpp>

UIOpenCV::UIOpenCV(): mat(500,500, CV_8UC3, {255,255,255}){
  Repaint();
}

void UIOpenCV::Plot(const Edge& e){
  Vertex from,to;
  std::tie(from,to) = e;
  int x1,y1,x2,y2;
  std::tie(x1,y1) = from;
  std::tie(x2,y2) = to;
  cv::line(mat, {x1,y1}, {x2,y2}, {0,255,0} ,1);
  Repaint();
  
}

void UIOpenCV::Plot(const Vertex& v){
  int x,y;
  std::tie(x,y) = v;
  cv::circle(mat, {x,y}, 5, {255,0,0} ,2);
  Repaint();
}

void UIOpenCV::Repaint(){
  cv::imshow("graph", mat);
}
