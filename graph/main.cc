#include "graph.h"
#include <queue>

int main(void) {
  Graph graph("graph.txt", 0);
  graph.ToString();
	graph.BFS(0);
  return 0;
}

