#include <iostream>
#include <memory>
#include <random>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ui.h"
#include "ui_opencv.h"
#include "types.h"

std::random_device generator;
std::uniform_int_distribution<int> distribution(1,500);


std::vector<Vertex> GenerateVertexes(std::uint16_t count){
  std::vector<Vertex> v(count);
  for(int i = 0 ; i < count ; ++i){
    v[i] = {distribution(generator), distribution(generator) }; 
  }
  return v;
}

std::vector<Vertex> GenerateEdges(const std::vector<Vertex> vertexes, double fill){
  std::set<Edge> connections;
  std::random_device generator;
  std::uniform_int_distribution<int> distribution(0,vertexes.size()-1);

  kk

  std::vector<Vertex> v(count);
  for(int i = 0 ; i < count ; ++i){
    v[i] = {distribution(generator), distribution(generator) }; 
  }
  return v;
}


int main(){
  auto ui = std::make_unique<UIOpenCV>();
  auto vertexes = GenerateVertexes(100);
  std::for_each(std::begin(vertexes), std::end(vertexes), [&ui](auto v){ui->Plot(v);});

  cv::waitKey(0);

}
