#ifndef __ALGORITHM_GRAPH_
#define __ALGORITHM_GRAPH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEGREE 128
#define MAX_NODE 128

struct edge
{
	int label;
	int weight;
};

struct graph_node
{
    int label;
    struct edge neighbor[MAX_DEGREE];
    int nbrcount;
};

struct graph
{
    struct graph_node nodes[MAX_NODE];
    int nnode;
    int nedge;
};

struct graph* graph_creat(struct graph* g, const char* filename, int directed);
void graph_print(struct graph* g);

#endif
