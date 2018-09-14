#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void insertion_sort(int *a, int n) {
    int p;
    int key;
    int i, k;
    for (p = 1; p < n; p++){
        if (p == n / 2){
            for (k = 0; k < n; k++){
                fprintf(stderr, "%d\n", a[k]);
            }
        }
        key = a[p]; 
        i = p;
        while (key < a[i-1] && i > 0){ 
            a[i] = a[i-1];
            i--;
        }
        a[i] = key;
        if (p == n / 2){
            for (k = 0; k < n; k++){
                fprintf(stderr, "%d\n", a[k]);
            }
        }
    }
}
void *emalloc(size_t s){
    void *a = malloc(s);
    if(a == NULL){
        fprintf(stderr, "failed.");
        exit(EXIT_FAILURE);
    }
    return a;
}

void *erealloc(void *a, size_t s){
    a = realloc(a, s);
    if(a == NULL){
        fprintf(stderr, "failed.");
        exit(EXIT_FAILURE);
    }
    return a;
}

void     flexarray_append(flexarray f, int num){
    if (f->capacity == f->itemcount){
        f->capacity = f->capacity * 2;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = num;
    f->itemcount++;        
}
void     flexarray_free(flexarray f){
    free(f->items);
    free(f);
}
flexarray flexarray_new(){
    flexarray f = emalloc(sizeof *f);
    f->itemcount = 0;
    f->capacity = 2;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}
void     flexarray_print(flexarray f){
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void     flexarray_sort(flexarray f){
    insertion_sort(f->items, f->itemcount);
}
