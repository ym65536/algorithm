#include "graph.h"

struct graph* graph_creat(struct graph* g, const char* filename, int directed)
{
    int node, edge;
    int node1, node2, weight;
    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        printf("open file graph.txt fail!\n");
        exit(0);
    }

    fscanf(fp, "%d %d", &(g->nnode), &(g->nedge));
    for (node = 0; node < g->nnode; node++)
        g->nodes[node].label = node;
    for (edge = 0; edge < g->nedge; edge++)
    {
        fscanf(fp, "%d %d %d", &node1, &node2, &weight);
        g->nodes[node1].label = node1;
        g->nodes[node1].neighbor[g->nodes[node1].nbrcount].node = node2;
        g->nodes[node1].neighbor[g->nodes[node1].nbrcount].weight = weight;
        g->nodes[node1].nbrcount++;
        if (!directed)
        {
            g->nodes[node2].label = node2;
            g->nodes[node2].neighbor[g->nodes[node2].nbrcount].node = node1;
            g->nodes[node2].neighbor[g->nodes[node2].nbrcount].weight = weight;
            g->nodes[node2].nbrcount++;
        }
    }

    return g;
}

void graph_print(struct graph* g)
{
    int i, j;

    for (i = 0; i < g->nnode; i++)
    {
        printf("node %d: ", i);
        for (j = 0; j < g->nodes[i].nbrcount; j++)
            printf("<%d,%d> ", g->nodes[i].neighbor[j].node, g->nodes[i].neighbor[j].weight);
        printf("\n");
    }
}

#if 0

int main(void)
{
	struct graph g;
	graph_creat(&g, "graph.txt", UNDIR);
	graph_print(&g);
}

#endif
