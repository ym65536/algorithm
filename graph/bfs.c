#include "graph.h"

#define MARK 1
#define UNMARK 0

char mark[MAX_NODE];
int seqno = MARK;

struct queue
{
	unsigned int data[MAX_NODE];
	int front;
	int rear;
};

void queue_init(struct queue* q)
{
	memset(q->data, 0, sizeof(q->data));
	q->front = q->rear = 0;
}

int queue_empty(struct queue* q)
{
	return (q->rear == q->front);
}

int queue_in(struct queue* q, unsigned int* x)
{
	if ((q->rear + 1) % MAX_NODE == q->front)
	{
		printf("queue is full!\n");
		return -1;
	}
	q->data[q->rear] = *x;
	q->rear = (q->rear + 1) % MAX_NODE;
	return 0;
}

int queue_out(struct queue* q, unsigned int* x)
{
	if (q->rear == q->front)
	{
		printf("queue is empty!\n");
		return -1;
	}
	*x = q->data[q->front];
	q->front = (q->front + 1) % MAX_NODE;
	return 0;
}

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
    graph_creat(&g, 0);
    graph_print(&g);

	seqno = MARK;
	memset(mark, UNMARK, sizeof(mark));
	BFS(&g, &g.nodes[1]);
	for (i = 0; i < g.nnode; i++)
		printf("%d-> ", mark[i]);
	printf("\n");

    return 0;
}
