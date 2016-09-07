#include "graph.h"
#include "queue.h"
#include <limits.h>

#define MARK 1
#define UNMARK 0

char mark[MAX_NODE];
int dist[MAX_NODE];
int parent[MAX_NODE];

int find_nearest(struct graph* g)
{
	int i = 0;
	int v = -1;
	int distance = INT_MAX;
	for (i = 0; i < g->nnode; i++)
	{
		if ((mark[i] == UNMARK) && (distance > dist[i]))
		{
			v = i;
			distance = dist[i];
		}
	}

	return v;
}

void dijkstra(struct graph* G, struct graph_node* start)
{
	int i = 0;
	for (i = 0; i < G->nnode; i++)
	{
		dist[i] = INT_MAX;
		mark[i] = UNMARK;
		parent[i] = -1;
	}

	int v = -1;
	dist[start->label] = 0;
	while ((v = find_nearest(G)) != -1) // find nearest unmarked vertex
	{
		mark[v] = MARK;
		struct graph_node* V = &G->nodes[v];
		for (i = 0; i < V->nbrcount; i++)
		{
			int weight = V->neighbor[i].weight;
			int w = V->neighbor[i].label;
			if (dist[w] > (dist[v] + weight))
			{
				dist[w] = dist[v] + weight;
				parent[w] = v;
			}
		}
	}
}

int main(void)
{
	struct graph G;
	int i;
    graph_creat(&G, "graph.txt", 0);
    graph_print(&G);

	dijkstra(&G, &G.nodes[0]);
	printf("<node, dist, parent>\n");
	for (i = 0; i < G.nnode; i++)
		printf("<%d, %d, %d>\n", i, dist[i], parent[i]);

    return 0;
}
