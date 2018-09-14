#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "rbt.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

struct rbt_node { 
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

static rbt right_rotate(rbt r){
    rbt temp;
    /* temp = emalloc(sizeof(r));*/
    temp = r;
    r = r->left;
    temp->left = r->right;
    r->right = temp;
    /* free(temp);*/
    
    return r;
}

static rbt left_rotate(rbt r){
    rbt temp;
    /* temp = emalloc(sizeof(r));*/
    temp = r;
    r = r->right;
    temp->right = r->left;
    r->left = temp;
    /* free(temp);*/
    return r;
}

static rbt rbt_fix(rbt r){
    if (IS_RED(r->left)){
        if (IS_RED(r->right)){
            if (IS_RED(r->left->left) || IS_RED(r->left->right) ||
                IS_RED(r->right->left) || IS_RED(r->right->right)){
                r->colour = RED;
                r->left->colour = BLACK;
                r->right->colour = BLACK;
            }
        } else {
            if(IS_RED(r->left->left)){
                /* 2. */
                r = right_rotate(r);
                r->right->colour = RED;
                r->colour = BLACK;
            } else if(IS_RED(r->left->right)){
                /* 4. this is OK */
                r->left = left_rotate(r->left);
                r = right_rotate(r);
                r->colour = BLACK;
                r->right->colour = RED;
            }
        }
    } else {
        if (IS_RED(r->right)){
            if (IS_RED(r->right->left)) {
                /* 6. this is OK */
                r->right = right_rotate(r->right);
                r = left_rotate(r);
                r->colour = BLACK;
                r->left->colour = RED;
            } else if (IS_RED(r->right->right)){
                /* 8. this is OK */
                r = left_rotate(r);
                r->left->colour = RED;
                r->colour = BLACK;
            }
        }
    }
    return r;
}

/*rbt rbt_delete(rbt r, char *str){
    rbt temp;
    int cmp;
    cmp = strcmp(r->key, str);
    if (cmp == 0){
        if (r->left == NULL && r->right == NULL){
            free(r->key);
            free(r);
            return NULL;
        }
        if (r->left == NULL){
            temp = r->right;
            free(r->key);
            free(r);
            return temp;
        }
        if (r->right == NULL){
            temp = r->left;
            free(r->key);
            free(r);
            return temp;
        }
        temp = r->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        strcpy(r->key, temp->key);
        r->right = rbt_delete(r->right, temp->key);
        r = rbt_fix(r);
        return r;    

       
    } else if (cmp > 0){
        r-> left = rbt_delete(r->left, str);
        return r;
    } else {
        r->right = rbt_delete(r->right, str);
        return r;
    }
    
    }*/

rbt rbt_free(rbt r){
    if (r->left != NULL){
        rbt_free(r->left);
    }
    if (r->right != NULL){
        rbt_free(r->right);
    }
    free(r->key);
    free(r);
    return r;
}

void rbt_inorder(rbt r, void f(char *s)) {
    if (r == NULL){
        return;
    }
    rbt_inorder(r->left, f);
    f(r->key);
    rbt_inorder(r->right, f);
}

rbt rbt_insert(rbt r, char *key){
    int cmp;
    if(r != NULL){
        cmp = strcmp(r->key, key);
        if (cmp == 0){
            return r;
        } else if (cmp > 0){
            r->left = rbt_insert(r->left, key);
        } else if (cmp < 0){
            r->right = rbt_insert(r->right, key);
        }
    } else {
        r = emalloc(sizeof *r);
        r->key = emalloc((strlen(key)+1) * sizeof r->key[0]);
        /* r->colour = emalloc(sizeof(rbt_colour)); */
        strcpy(r->key, key);
        r->left = rbt_new();
        r->right = rbt_new();
        r->colour = RED;
    }
    r = rbt_fix(r);
    return r;
}

rbt rbt_new(){
    return NULL;
}

void rbt_preorder(rbt r, void f(char *s)) {
    if (r == NULL){
        return;
    }
    if (IS_RED(r)){
        printf("Red: ");
        f(r->key);
    } else {
        printf("Black: ");
        f(r->key);
    }
    rbt_preorder(r->left, f);
    rbt_preorder(r->right, f);
}

int rbt_search(rbt r, char *key) {
    int cmp;
    if(r == NULL){
        return 0;
    }
    cmp = strcmp(r->key, key);
    if (cmp == 0){
        return 1;
    }
    if (cmp > 0){
        return rbt_search(r->left, key);
    }
    if (cmp < 0){
        return rbt_search(r->right, key);
    }
    return -1;
}



