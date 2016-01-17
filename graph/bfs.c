#include "graph.h"
#include "queue.h"

#define MARK 1
#define UNMARK 0

char mark[MAX_NODE];
int seqno = MARK;

void BFS(struct graph* g, struct graph_node* v)
{
	struct queue q;
	queue_init(&q);
	mark[v->label] = seqno++;
	printf("preWork: %d\n", v->label);
	queue_in(&q, (unsigned int* )&v);
	while (!queue_empty(&q))
	{
		struct graph_node* w;
		int k;
		queue_out(&q, (unsigned int* )&w);
		for (k = 0; k < w->nbrcount; k++)
		{
			struct graph_node* x = &g->nodes[w->neighbor[k]];
			if (!mark[x->label])
			{
				mark[x->label] = seqno++;
				printf("preWork: %d\n", x->label);
				queue_in(&q, (unsigned int*)&x);
			}
		}
	}
}

struct graph g;

int main(void)
{
	int i;
    graph_creat(&g, "graph.txt", 1);
    graph_print(&g);

	seqno = MARK;
	memset(mark, UNMARK, sizeof(mark));
	BFS(&g, &g.nodes[0]);
	for (i = 0; i < g.nnode; i++)
		printf("%d-> ", mark[i]);
	printf("\n");

    return 0;
}
