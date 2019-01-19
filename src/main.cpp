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
#include "graph.h"

std::random_device rd;
std::uniform_int_distribution<int> distribution(50,450);

std::vector<Vertex> GenerateVertexes(std::uint16_t count){
  std::vector<Vertex> v(count);
  for(int i = 0 ; i < count ; ++i){
    v[i] = {distribution(rd), distribution(rd) }; 
  }
  return v;
}


std::vector<Connection> GenerateMinimalTree(const std::vector<Vertex> vertexes){
  std::vector<Connection> connections { 0 };
  std::vector<Connection> all_connections;

  for(unsigned int i = 1 ; i < vertexes.size() ; ++i){
    std::uniform_int_distribution<int> dist(0, i-1);
    connections.push_back({i, dist(rd)});      
  }

  return connections;
}

std::vector<Connection> GenerateConnections(const std::vector<Vertex> vertexes, double fill){
  std::vector<Connection> all_connections;

  for(unsigned int i = 0 ; i < vertexes.size() ; ++i){
    for(unsigned int j = 0 ; j < vertexes.size() ; ++j){
      all_connections.push_back({i,j});
    }
  }

  std::random_shuffle(std::begin(all_connections), std::end(all_connections));
  if( fill*all_connections.size() < vertexes.size()-1 ){
    throw std::runtime_error("fill factor must be greater than number of connection required to connect whole tree");
  }
  all_connections.resize(std::floor(fill*all_connections.size() - (vertexes.size()-1)));
  return all_connections;
}


int main(int argc, const char **argv){
  auto ui = std::make_unique<UIOpenCV>();
  auto vertexes = GenerateVertexes(20);
  auto connections = GenerateMinimalTree(vertexes);
  auto filling_connections = GenerateConnections(vertexes, 0.1);
  connections.insert(std::end(connections), std::begin(filling_connections), std::end(filling_connections));
  std::set<Connection> connections_set(std::begin(connections), std::end(connections));
  connections.clear();
  connections.insert(std::end(connections), std::begin(connections_set), std::end(connections_set));

  Graph g = {vertexes, connections};
  ui->Plot(g);
  ui->Update();
  cv::waitKey(-1);
}
