#include "graph.h"
#include "queue.h"

int indegree[MAX_NODE];
int sort[MAX_NODE];

void init_indegree(struct graph* g, int indegree[])
{
	int node;
	int nbr;
	for (node = 0; node < g->nnode; node++)
	{
		for (nbr = 0; nbr < g->nodes[node].nbrcount; nbr++)
		{
			int neighbor = g->nodes[node].neighbor[nbr].label;
			indegree[neighbor]++;
		}
	}
}

void topsort(struct graph* g)
{
	int node;
	int v, w;
	int j, k;
	struct queue q;
	queue_init(&q);

	init_indegree(g, indegree);
	for (node = 0; node < g->nnode; node++)
	{
		if (indegree[node] == 0) // indegree is zero
			queue_in(&q, (unsigned int* )&node);
	}

	j = 0;
	while (!queue_empty(&q))
	{
		queue_out(&q, (unsigned int*)&v);
		sort[j] = v;
		j++;
		struct graph_node V = g->nodes[v];
		for (k = 0; k < V.nbrcount; k++)
		{
			w = V.neighbor[k].label;
			indegree[w]--;
			if (indegree[w] == 0) 
				queue_in(&q, (unsigned int* )&w);
		}
	}
}

int main(void)
{
	struct graph g;
	int k;

	graph_creat(&g, "graph.txt", 1); // create DAG
	graph_print(&g);

	topsort(&g);
	printf("topological sort: ");
	for (k = 0; k < g.nnode; k++)
		printf("%d-> ", sort[k]);
	printf("\n");

	return 0;
}
