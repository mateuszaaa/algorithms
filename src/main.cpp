#include <iostream>
#include <memory>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ui.h"
#include "ui_console.h"
#include "types.h"

int main(){
  auto ui = std::make_unique<UiConsole>();
  Vertex v{1,2};
  Edge e{ {0,2}, {3,4} };
  ui->PlotEdge(e);
  ui->PlotVertex(v);

  cv::Mat M(500,500, CV_8UC3);
  cv::imshow("graph", M);
  cv::waitKey(0);

}
