#ifndef __ALGORITHM_GRAPH_
#define __ALGORITHM_GRAPH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>

struct Edge {
  Edge(int node, int weight): id(node), w(weight) {};
	int id;
	int w;
};

class Graph {
 public:
  std::vector<std::vector<Edge>> nodes_; // node_id, edge_id
  std::vector<int> degrees_;

 public:
  Graph(const char* file, int directed = 0);
  void ToString();

  void BFS(int start_node); 
};

#endif

