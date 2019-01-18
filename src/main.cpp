#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <set>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ui_opencv.h"
#include "connection.h"
#include "vertex.h"
#include "edge.h"

std::random_device rd;
std::uniform_int_distribution<int> distribution(1,500);

Edge toEdge(std::vector<Vertex> vertexes, Connection c){
  return { vertexes[std::get<0>(c)], vertexes[std::get<1>(c)] };
}

std::vector<Vertex> GenerateVertexes(std::uint16_t count){
  std::vector<Vertex> v(count);
  for(int i = 0 ; i < count ; ++i){
    v[i] = {distribution(rd), distribution(rd) }; 
  }
  return v;
}

std::vector<Connection> GenerateConnections(const std::vector<Vertex> vertexes, double fill){
  std::vector<Connection> connections { 0 };

  for(unsigned int i = 1 ; i < vertexes.size() ; ++i){
    std::uniform_int_distribution<int> dist(0, i-1);
    connections.push_back({i, dist(rd)});      
  }
  return connections;
}


int main(int argc, const char **argv){
  int delay = 10;

  if(argc == 2){
    delay = std::atoi(argv[1]);
  }

  auto ui = std::make_unique<UIOpenCV>();
  auto vertexes = GenerateVertexes(100);
  auto connections = GenerateConnections(vertexes, 1);
  std::vector<Edge> edges;

  std::transform(std::begin(connections), std::end(connections), std::back_inserter(edges), [&vertexes](auto c){ return toEdge(vertexes,c); });

  for(auto v:vertexes){
    ui->Plot(v, Color::Blue, Thickness::Normal);
  }

  for(auto e: edges){
    ui->Plot(e, Color::Green, Thickness::Normal);
  }

  for(auto e: edges){
    ui->Plot(e, Color::Red, Thickness::Slim);
    ui->Update();
    if(delay)
      cv::waitKey(delay);
  }

  ui->Update();
  cv::waitKey(-1);

}
