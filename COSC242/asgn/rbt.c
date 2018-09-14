#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "mylib.h"

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
 * This file creates a red black tree
 */

/*To decide if a node is black or red*/
#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/*creates named members of various types of the red black tree
 */
struct rbt_node {
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

/*This function gets a red-black tree into its starting.
  @return rbt a new null rbt
*/
rbt rbt_new(){
    return NULL;
	
}

/*do this right rotation to fix up the colour violation
  @param r rbt the rbt we need
  @return r rbt the rbt after right rotate
*/
static rbt right_rotate(rbt r){
    rbt temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    return r;
}

/*do this left rotation to fix up the colour violation
  @param r rbt the rbt we need
  * @return r rbt the rbt after left rotate
  */
static rbt left_rotate(rbt r){
    rbt temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    return r;
}

/**
 * Maintain this tree is still a rbt tree
 * @param r rbt the rbt we need
 * @return r rbt the rbt with the structure
 *
 */
static rbt rbt_fix(rbt r){
    if (IS_RED(r->left) && IS_RED(r->left->left)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else if (IS_BLACK(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r = right_rotate(r);
        }
    }else if (IS_RED(r->left) && IS_RED(r->left->right)){
        if (IS_RED(r->right)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else if (IS_BLACK(r->right)){
            r->colour = RED;
            r->left->right->colour = BLACK;
            r->left = left_rotate(r->left);
            r = right_rotate(r);
        }
    }else if (IS_RED(r->right) && IS_RED(r->right->left)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else if (IS_BLACK(r->left)){
            r->right->left->colour = BLACK;
            r->colour = RED;
            r->right = right_rotate(r->right);
            r = left_rotate(r);
        }
    }else if (IS_RED(r->right) && IS_RED(r->right->right)){
        if (IS_RED(r->left)){
            r->colour = RED;
            r->left->colour = BLACK;
            r->right->colour = BLACK;
        }else if (IS_BLACK(r->left)){
            r->right->colour = BLACK;
            r->colour = RED;
            r = left_rotate(r);
        }
    }
    return r;
}

/**
 * Insert new nod in this rbt
 * @param b rbt the rbt we need
 * @param key char * the string that we need to insert
 * @return b rbt the new rbt
 *
 */
rbt rbt_insert(rbt b, char *key){
    if(b == NULL){
        b = emalloc(sizeof *b);
        b->key = emalloc((strlen(key)+1) * sizeof b->key[0]);
        strcpy(b->key, key);
        b-> colour = RED;
        b->left = rbt_new();
        b->right = rbt_new();
    }    else if(strcmp(b->key,key) < 0){
        b->right = rbt_insert(b->right, key);
    }
    else if(strcmp(b->key,key) >= 0){
        b->left = rbt_insert(b->left, key);
    }
    b = rbt_fix(b);
    return b;
}


/**
 * Traverse the rbt with inorder
 * @param b rbt the rbt we need
 * @param f void the function we need to use with each items
 *
 */
void rbt_inorder(rbt b, void f(char *s)){
    if(b == NULL){
        return;
    }
    rbt_inorder(b->left,f);
    f(b->key);
    rbt_inorder(b->right,f);
}

/**
 * Traverse the rbt with preorder
 * @param b rbt the rbt we need
 * @param f void the function we need to use with every items
 *
 */
void rbt_preorder(rbt b, void f(char *s)){
    if(b == NULL){
        return;
    }
    f(b->key);
    rbt_preorder(b->left,f);
    rbt_preorder(b->right,f);
}


/**
 * Free the memory
 * @param b rbt the rbt we need
 * @return NULL 
 *
 */
rbt rbt_free(rbt b){
    if(b == NULL){
        return b;
    }
 
    b->left = rbt_free(b->left);
    b->right = rbt_free(b->right);
    free(b->key);
    free(b);
    return NULL;
}


/**
 * Check if this one in the rbt
 * @param b rbt the rbt we need
 * @param str char * the string that need to search
 * @return result int the value show if this one in the rbt
 *
 */
int rbt_search(rbt b, char *str){
    if (b == NULL){
        return 0;
    }else if (strcmp(str,b->key) == 0){
        return 1;
    }else if (strcmp(str,b->key) < 0){
        return rbt_search(b->left, str);
    }else if (strcmp(str,b->key) > 0){
        return rbt_search(b->right, str);
    }
    return 0;
}


/**
 * Delete the root from rbt
 * @param b rbt the rbt that need
 * @return b rbt the new rbt with no old root
 *
 */
rbt root_delete(rbt b){
    rbt q = rbt_new();
    rbt s = rbt_new();
    char *temp;
    if(b->left == NULL && b->right == NULL) {
        free(b->key);
        free(b);
        b = NULL;
    } else if(b->right == NULL){
        q = b;
        b = b->left;
        free(q->key);
        free(q);
    } else if(b->left == NULL){
        q=b;
        b = b->right;
        free(q->key);
        free(q);
    }  else {
        s = b->right;
        while(s->left != NULL){
            s = s->left;
        }
        temp = b->key;
        b->key = s->key;
        s->key = temp; 
        b->right = rbt_delete(b->right, s->key);
    }
    return b;
}



/**
 * Delete one from rbt
 * @param b rbt the rbt we need
 * @param key char * the string need to delete
 * @return b rbt the new rbt without the deleted one
 *
 */
rbt rbt_delete(rbt b, char*key){
    if(b == NULL){
        return NULL;
    }
    else{
        if(strcmp(b->key,key) == 0)
            b = root_delete(b);
        else if(strcmp(b->key, key) > 0){
            b->left = rbt_delete(b->left, key);
        }
        else if(strcmp(b->key, key) <= 0){
            b->right = rbt_delete(b->right, key);
        }
    }
    return b;
}

