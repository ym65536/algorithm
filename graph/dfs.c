#include "graph.h"

#define MARK 1
#define UNMARK 0

int mark[MAX_NODE];

void BFS(struct graph* g, struct graph_node* v)
{
	int k;
	mark[v->label] = MARK;
	printf("preWork: %d\n", v->label);
	for (k = 0; k < v->nbrcount; k++)
	{
		int neighbor = v->neighbor[k];
		struct graph_node* w = &g->nodes[neighbor];
		if (mark[w->label] == UNMARK)
			BFS(g, w);
		printf("postWork: %d\n", v->label);
	}
}

struct graph g;

int main(void)
{
    graph_creat(&g, 0);
    graph_print(&g);
	BFS(&g, &g.nodes[1]);

    return 0;
}
