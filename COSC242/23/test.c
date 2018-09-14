#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "graph.h"
/**
   Ali Morris Lab 21 Graphs I, 3/10/17
*/
/**
   reads a file, creates a graph and prints the adjacent nodes and distances
*/
int main(void){
    graph g;
    int size, a, b;
    scanf("%d", &size);
    
    g = graph_new(size);

    while (2 == scanf("%d%d", &a, &b)){
        g = graph_add_edges(g, a, b);
    }

    graph_print(g);
    
    g = graph_dfs(g);

    g = graph_free(g);

    return EXIT_SUCCESS;
}
