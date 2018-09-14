#ifndef RBT_H_
#define RBT_H_
 
#include <stdio.h>

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   header for rbt.c
*/

typedef enum {RED, BLACK} rbt_colour;
typedef struct rbt_node *rbt;
 
extern rbt rbt_new();
extern rbt rbt_delete(rbt b, char *key);
extern rbt rbt_free(rbt b);
extern int rbt_search(rbt b, char *key);
extern rbt rbt_insert(rbt b, char *key);
extern void rbt_inorder(rbt b, void f(char *s));
extern void rbt_preorder(rbt b, void f(char *s));
extern rbt root_delete(rbt b);
 
#endif
