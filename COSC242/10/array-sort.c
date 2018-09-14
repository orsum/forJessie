#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

void array_sort(int *my_array, int itemcount) {
    int p;
    int key;
    int i;
    for (p = 1; p < itemcount; p++){
        key = my_array[p]; 
        i = p;
        while (key < my_array[i-1] && i > 0){ 
            my_array[i] = my_array[i-1];
            i--;
        }
        my_array[i] = key;
    }
}

static void array_print(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

int main(void) {
    
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = malloc(capacity * sizeof my_array[0]);
       
    while (1 == scanf("%d", &item)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
        }
        my_array[itemcount++] = item;
    }

    array_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);
    return EXIT_SUCCESS;
}
