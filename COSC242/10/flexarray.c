#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

/* creates an object that consists of named members of various types */
struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

/* creates a new flex array of default size and sets default values */
flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
/* adds a new item to the flexarray and doubles the size if the capacity is
   reached  */
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount] = num;
    f->itemcount++;
}
/* Prints each item in the flexarray  */
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%i\n", f->items[i]);
    }
}

/* sorts the items in the flex array using merge sort */
void flexarray_sort(flexarray f) {
    void *w = emalloc(f->itemcount * sizeof f[0]);
    merge_sort(f->items, w, f->itemcount);
    free(w);
}

/* frees the memory allocated to the flex array */
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
