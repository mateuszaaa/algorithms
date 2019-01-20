#include "prim.h"
#include "vertex.h"
#include "connection.h"
#include <algorithm>


Graph Prime(Vertex v, const Graph& g){
  auto it = std::find(std::begin(g.vertexes), std::end(g.vertexes), v);
  if (it == std::end(g.vertexes)){
    throw std::runtime_error("given vertex does not belong to graph");
  }


  Graph result = { {}, {} };

  int current_id = 0;
  while( g.vertexes.size() != result.vertexes.size() ){
    const auto &connections  = g.connections[current_id];
    std::min_element(std::begin(connections), std::end(connections),
        [](auto lhs, auto rhs){
          retu
        }
    for(const auto& c: g.connections[current_id]){
    }
  }
  
  // while(result.vertexes.size() != g.vertexes.size()){
  //   for(auto id : ids){
  //     
  //     std::min
  //   }
  // }
}
