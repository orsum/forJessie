#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"

struct bst_node { 
    char *key;
    bst left;
    bst right;
};

bst   bst_delete(bst b, char *str){
    bst temp;
    int cmp;
    /*if (bst_search(b, str) == 0){
        return b;
        }*/
    cmp = strcmp(b->key, str);
    if (cmp == 0){
        if (b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            return NULL;
        }
        if (b->left == NULL){
            temp = b->right;
            free(b->key);
            free(b);
            return temp;
        }
        if (b->right == NULL){
            temp = b->left;
            free(b->key);
            free(b);
            return temp;
        }
        temp = b->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        strcpy(b->key, temp->key);
        b->right = bst_delete(b->right, temp->key);
        return b;    

        /*(if node is a leaf, free key, then node, then set pointer to null)
          (if node as 1 child, pointer->child, free key, free node)
          (if node has 2 children, find the sucessor, swap the keys, delete the
          key from the right subtree)*/
    } else if (cmp > 0){
        b-> left = bst_delete(b->left, str);
        return b;
    } else {
        b->right = bst_delete(b->right, str);
        return b;
    }
    
}

bst bst_free(bst b){
    if (b->left != NULL){
        bst_free(b->left);
    }
    if (b->right != NULL){
        bst_free(b->right);
    }
    free(b->key);
    free(b);
    return b;
}

void bst_inorder(bst b, void f(char *s)) {
    if (b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *key){
    int cmp;
    if (b == NULL) {
        b = emalloc(sizeof(*b));
        b->key = emalloc(sizeof(strlen(key)+1));
        strcpy(b->key, key);
        b->left = bst_new();
        b->right= bst_new();
        return b;
    }
    cmp = strcmp(b->key, key);
    if (cmp == 0){
        return b;
    }
    if (cmp > 0){
        b->left = bst_insert(b->left, key);
        return b;
    }
    if (cmp < 0){
        b->right = bst_insert(b->right, key);
        return b;
    }
    return NULL;
}

bst bst_new(){
    return NULL;
}

void bst_preorder(bst b, void f(char *s)) {
    if (b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

int bst_search(bst b, char *key) {
    int cmp;
    if(b == NULL){
        return 0;
    }
    cmp = strcmp(b->key, key);
    if (cmp == 0){
        return 1;
    }
    if (cmp < 0){
        return bst_search(b->left, key);
    }
    if (cmp > 0){
       return bst_search(b->right, key);
    }
    return -1;
}
