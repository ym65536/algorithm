#include "graph.h"
#include <queue>

using namespace std;

Graph::Graph(const char* filename, int directed) {
  int nnode, nedge;
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("open file graph.txt fail!\n");
    exit(0);
  }
  fscanf(fp, "%d %d", &nnode, &nedge);
  degrees_.resize(nnode);
  nodes_.resize(nnode);
  int node1, node2, weight;
  for (int edge = 0; edge < nedge; ++ edge) {
    fscanf(fp, "%d %d %d", &node1, &node2, &weight);
    nodes_[node1].emplace_back(node2, weight);
    ++ degrees_[node1];
    if (!directed) {
      nodes_[node2].emplace_back(node1, weight);
      ++ degrees_[node2];
    }
  }
}

void Graph::ToString() {
  for (int i = 0; i < nodes_.size(); ++ i) {
    printf("node %d: ", i);
    for (int j = 0; j < nodes_[i].size(); ++ j)
        printf("<%d, %d>", nodes_[i][j].id, nodes_[i][j].w);
    printf("\n");
  }
}

void Graph::BFS(int start_node) {
  queue<int> store;
  int seqno = 0;
  vector<int> marked(nodes_.size(), 0);
  store.push(start_node);
  marked[start_node] = seqno++;
	printf("preWork: <%d, %d>\n", start_node, marked[start_node]);
	while (!store.empty()) {
    auto node = store.front();
    store.pop();
		for (auto k = 0; k < nodes_[node].size(); ++ k) {
      auto& edge = nodes_[node][k];
			if (!marked[edge.id]) {
				marked[edge.id] = seqno++;
	      printf("preWork: <%d, %d>\n", edge.id, marked[edge.id]);
        store.push(edge.id);
			}
		}
	}
}

void Graph::DFS(int start_node, vector<int>& marked, int& seqno) {
  marked[start_node] = ++seqno;
	printf("preWork: <%d, %d>\n", start_node, marked[start_node]);
	for (int k = 0; k < nodes_[start_node].size(); ++ k) {
    auto& edge = nodes_[start_node][k];
		if (marked[edge.id] == 0) {
			DFS(edge.id, marked, seqno);
		  printf("postWork: <%d %d>\n", edge.id, marked[edge.id]);
    }
	}
}

