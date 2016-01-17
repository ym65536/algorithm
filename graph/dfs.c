#include "graph.h"

#define MARK 1
#define UNMARK 0

char mark[MAX_NODE];
int seqno = MARK;

// just for connected graph
void DFS(struct graph* g, struct graph_node* v)
{
	int k;
	mark[v->label] = seqno++;
	printf("preWork: %d\n", v->label);
	for (k = 0; k < v->nbrcount; k++)
	{
		int neighbor = v->neighbor[k];
		struct graph_node* w = &g->nodes[neighbor];
		if (mark[w->label] == UNMARK)
			DFS(g, w);
		printf("postWork: %d\n", v->label);
	}
}

struct graph g;

int main(void)
{
	int i;
    graph_creat(&g, 1);
    graph_print(&g);

	DFS(&g, &g.nodes[0]);
	for (i = 0; i < g.nnode; i++)
		printf("%d-> ", mark[i]);
	printf("\n");

    return 0;
}
