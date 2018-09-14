#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void insertion_sort(int *a, int n){
    int p, key, i, j;
    for (p = 1; p < n/2; p++){
        key = a[p];
        i = p;
        while (key < a[i-1] && i > 0){
            a[i] = a[i-1];
            i--;
        }
        a[i] = key;
    }
    for (j = 0; j < n; j++){
        fprintf(stderr, "%d\n", a[j]);
    }
    for (; p < n; p++){
        key = a[p];
        i = p;
        while (key < a[i-1] && i > 0){
            a[i] = a[i-1];
            i--;
        }
        a[i] = key;
    }
}

void *emalloc(size_t s){
    void *result = malloc(s);
    if (result == NULL){
        fprintf(stderr, "Mem allo failed");
        exit(EXIT_FAILURE);
    }
    return result;
}

int *erealloc(int *a, size_t s){
    a = realloc(a, s);
    if (a == NULL){
        fprintf(stderr, "Mem allo failed");
        exit(EXIT_FAILURE);
    }
    return a;

}

flexarray flexarray_new() {
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = malloc(f->capacity * sizeof f->items[0]);
    return f;
    /* initialise flexarray structure (including items array) */
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity){
        f->capacity = f->capacity * 2;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = num;
    f->itemcount++;
    /* add an item to the flexarray, expanding as necessary */
}

void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
    /* a "for" loop to print out each cell of f->items */
}

void flexarray_sort(flexarray f) {
    insertion_sort(f->items, f->itemcount);
    /* sort into ascending order */
}

void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
    /* free the memory associated with the flexarray */
}


