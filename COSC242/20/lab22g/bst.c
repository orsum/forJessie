#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"

struct bstnode {
    char *key;
    bst left;
    bst right;
};

bst bst_free(bst b){
    if(b->right != NULL){
        b->right = bst_free(b->right);
    }
    if (b->left != NULL){
        b->left = bst_free(b->left);
    }
    free(b->key);
    free(b);
    return b;
}

void bst_inorder(bst b, void f(char *str)){
    if(b==NULL){
        return;
    }

    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *str){
    int cmp;
    
    if (b == NULL){
        b = emalloc(sizeof (*b));
        b->key = emalloc((strlen(str) + 1) * sizeof (b->key[0]));
        strcpy(b->key, str);
        b->left = bst_new();
        b->right = bst_new();
        return b;
        
    } else {
        
        cmp = strcmp(b->key, str);
        if (cmp == 0){
            return b;
        } else if (cmp > 0){
            b->left = bst_insert(b->left, str);
        } else {
            b->right = bst_insert(b->right, str);
        }
        return b;
    }
}

bst bst_new(){
    
    return NULL;
}

void bst_preorder(bst b, void f(char *str)){
    if(b==NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
   
    bst_preorder(b->right, f);
}

int bst_search(bst b, char *str){
    int cmp;
    if (b == NULL){
        return 0;
    }
    cmp = strcmp(str, b->key);
    if (cmp == 0){
        return 1;
    }
    if (cmp < 0){
        return bst_search(b->left, str);
    }
    if (cmp > 0){
        return bst_search(b->right, str);
    }
    return 0;
}
