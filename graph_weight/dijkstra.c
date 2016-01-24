#include "graph.h"

#define MAXINT	0x0000FFFF

int visit[MAX_NODE];
int dist[MAX_NODE];
int parent[MAX_NODE];

int find_min(struct graph* g)
{
	int v = 0;
	int k = 0;
	int d = MAXINT;
	for (k = 0; k < g->nnode; k++)
	{
		if (visit[k])
			continue;
		if (d > dist[k])
		{
			d = dist[k];
			v = k;
		}
	}

	return v;
}

void dijkstra(struct graph* g, struct graph_node* node)
{
	int k;
	int v, w;
	int weight;
	for (k = 0; k < g->nnode; k++)
	{
		visit[k] = 0;
		dist[k] = MAXINT;
		parent[k] = -1;
	}

	v = node->label;
	dist[v] = 0;
	
	v = find_min(g);
	while (!visit[v])
	{
		struct graph_node* V = &g->nodes[v];
		visit[V->label] = 1;
		for (k = 0; k < V->nbrcount; k++)
		{
			w = V->neighbor[k].node;
			weight = V->neighbor[k].weight;
			if (dist[w] > dist[V->label] + weight)
			{
				dist[w] = dist[V->label] + weight;
				parent[w] = V->label;
			}
		}
		v = find_min(g);
	}
}

int main(void)
{
	int k;
	struct graph g;
	graph_creat(&g, "graph.txt", UNDIR);
	graph_print(&g);

	dijkstra(&g, &g.nodes[0]);
	printf("dist: ");
	for (k = 0; k < g.nnode; k++)
	{
		printf("%d ", dist[k]);
	}
	printf("\n");

	printf("parent: ");
	for (k = 0; k < g.nnode; k++)
	{
		printf("%d ", parent[k]);
	}
	printf("\n");

	return 0;
}

