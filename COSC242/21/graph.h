#ifndef GRAPH_H_
#define GRAPH_H_

#include <stddef.h>

typedef struct graphrec *graph;

extern graph graph_new(int size);
extern graph graph_add_edges(graph g, int a, int b);
extern graph graph_add_2edges(graph g, int a, int b);
extern graph graph_free(graph g);
extern void graph_print(graph g);
extern graph graph_bfs(graph g, int source);

#endif
