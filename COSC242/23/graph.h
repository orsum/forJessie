#ifndef GRAPH_H_
#define GRAPH_H_

#include <stddef.h>

/**
   defines the pointer to grpahrec as graph
 */
typedef struct graphrec *graph;


/**
   creates a graph and allocates memory for all attributes
   @param size - the number of nodes the new graph will have
   @return the new graph
*/
extern graph graph_new(int size);

/**
   adds a unidirectional edge to the graph
   @param g - the graph to be added to
   @param a - the node from
   @param b - the node to
   @return the adjusted graph
*/
extern graph graph_add_edges(graph g, int a, int b);

/**
   adds a bidirectional edge to the graph
   @param g - the graph to be added to
   @param a - the node from
   @param b - the node to
   @return the adjusted graph
*/
extern graph graph_add_2edges(graph g, int a, int b);

/**
   frees any memory allocated for the graph
   @param the graph to be freed
   @return null
*/
extern graph graph_free(graph g);

/**
   prints the nodes adjacent for each node
   @param the graph to be printed
*/
extern void graph_print(graph g);

/**
   visits adjaent nodes and adds the distance
   @param g - the graph with the nodes
   @param v - the key of the node to check from
   @return the adjusted graph
 */
extern graph visit(graph g, int v);

/**
   does a depth first search to calculate the distances from one node to all
   others
   @param g - the graph with the nodes
   @return the adjusted graph
 */
extern graph graph_dfs(graph g);

#endif
