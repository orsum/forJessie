#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "graph.h"
#include "queue.h"

/**
   enum for defining whether a node has been checked for distance or not during
   searches
*/
typedef enum { UNVISITED, VISITED_SELF, VISITED_DESCENDANTS } state_t;

/**
   struct for the array of values for bfs
*/
struct vertexrec {
    int predecessor;
    int distance;
    state_t state;
    int finish;
};

/**
   struct to hold all the attributes of the graph
*/
struct graphrec {
    int size;
    struct vertexrec *vertices;
    int **edges;
};

/**
   creates a graph and allocates memory for all attributes
   @param size - the number of nodes the new graph will have
   @return the new graph
*/
graph graph_new(int size){
    int i, j;
    graph g = emalloc(sizeof *g);
    g->size = size;
    g->vertices = emalloc(size * sizeof *(g->vertices));
    g->edges = emalloc(size * sizeof g->edges[0]);
    for (i = 0; i < size; i++){
        g->edges[i] = emalloc(size * sizeof g->edges[0][0]);
        for (j = 0; j < size; j++){
            g->edges[i][j] = 0;
        }
    }
    return g;
}

/**
   adds a unidirectional edge to the graph
   @param g - the graph to be added to
   @param a - the node from
   @param b - the node to
   @return the adjusted graph
*/
graph graph_add_edges(graph g, int a, int b){
    g->edges[a][b] = 1;
    return g;
}

/**
   adds a bidirectional edge to the graph
   @param g - the graph to be added to
   @param a - the node from
   @param b - the node to
   @return the adjusted graph
*/
graph graph_add_2edges(graph g, int a, int b){
    g->edges[a][b] = 1;
    g->edges[b][a] = 1;
    return g;
}

/**
   frees any memory allocated for the graph
   @param the graph to be freed
   @return null
*/
graph graph_free(graph g){
    int i;
    for (i = 0; i < g->size; i++){
        free(g->edges[i]);
    }
    
    free(g->edges);
    
    
    free(g->vertices);
    
    free(g);
    
    return NULL;
}

/**
   prints the nodes adjacent for each node
   @param the graph to be printed
*/
void graph_print(graph g){
    int i, j;
    printf("adjacency list:\n");
    for (i = 0; i < g->size; i++){
        printf("%i  |  ", i);
        for (j = 0; j < g->size; j++){
            if(g->edges[i][j] == 1){
                printf("%i, ", j);
            }
        }
        printf("\n");
    }
}

/**
   prints the results of the bfs
   @param the graph to be printed
*/
void print_bfs(graph g){
    int i;
    printf("\nvertex distance pred\n");
    for (i = 0; i < g->size; i++){
        printf("%6d%9d%5d\n", i, g->vertices[i].distance,
               g->vertices[i].predecessor);
    }
}

/**
   does a breadth first search of the graph to find the distance from one node
   to all the others. Using a linked list queue
   @param g - the graph to be searched
   @param source - the node each distance is calculated from
   @return the adjusted graph
*/
graph graph_bfs(graph g, int source){
    queue q = queue_new();
    int i, u, v;
    
    for (i = 0; i < g->size; i++){
        
        g->vertices[i].state = UNVISITED;
        g->vertices[i].distance = -1;
        g->vertices[i].predecessor = -1;
        
    }
    
    g->vertices[source].state = VISITED_SELF;
    g->vertices[source].distance = 0;
    
    enqueue(q, source);
    
    while (queue_size(q) > 0){
        
        u = dequeue(q);
        
        for (v = 0; v < g->size; v++){
            
            if(g->edges[u][v] == 1 && g->vertices[v].state == UNVISITED){
                
                g->vertices[v].state = VISITED_SELF;
                g->vertices[v].distance = 1 + g->vertices[u].distance;
                g->vertices[v].predecessor = u;
                
                enqueue(q, v);
            }
        }
        
        g->vertices[u].state = VISITED_DESCENDANTS;
    }
    
    queue_free(q);
    
    print_bfs(g);
    
    return g;
}

/*
  graph_dfs(graph) {
  int i;
  for (i = 0;
  for each vertex in the graph {
  set its state to unvisited
  set its predecessor as non-existent (use -1)
  }
  initialise the step to 0
  for each vertex v in graph {
  if its state is unvisited {
  visit(v)
  }
  }
  }
  visit(vertex v) {
  set v’s state as visited_self
  increment step
  set distance to v as step
  for each vertex u adjacent to v {
  if it is unvisited {
  set its predecessor as v
  visit(u)
  }
  }
  increment step
  set v’s state as visited_descendants
  set v’s finish value to step
  }
*/
