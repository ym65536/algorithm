#include "graph.h"

struct graph* graph_creat(struct graph* g, int directed)
{
    int i;
    int node1, node2;
    FILE* fp = fopen("graph.txt", "r");
    if (!fp)
    {
        printf("open file graph.txt fail!\n");
        exit(0);
    }

    fscanf(fp, "%d %d", &(g->nnode), &(g->nedge));
    for (i = 0; i < g->nedge; i++)
    {
        fscanf(fp, "%d %d", &node1, &node2);
        g->nodes[node1].label = node1;
        g->nodes[node1].neighbor[g->nodes[node1].nbrcount] = node2;
        g->nodes[node1].nbrcount++;
        if (!directed)
        {
            g->nodes[node2].label = node2;
            g->nodes[node2].neighbor[g->nodes[node2].nbrcount] = node1;
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
            printf("%d ", g->nodes[i].neighbor[j]);
        printf("\n");
    }
}

