#include "graph.h"

using namespace std;

int main(void) {
  Graph graph("graph.txt", 0);
  graph.ToString();
  printf("BFS:\n");
	graph.BFS(0);
  printf("DFS:\n");
  int seqno = 0;
  vector<int> marked(graph.nodes_.size());
  graph.DFS(0, marked, seqno);
  return 0;
}

