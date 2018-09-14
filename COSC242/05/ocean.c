#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;       /* grid-reference east-west                             */
    int y;       /* grid-reference north-south                           */
    double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};

void print_ocean_datum(struct ocean_datum *o) {
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum *o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

void insertion_sort(struct ocean_datum *o, int n) {
    int p;
    char *key;
    int i;
    
    for (p = 1; p < n; p++){
        key = o[p]; /* saves the one to compare */
        i = p;
        while (i > 0 && strcmp(key, a[i-1]) < 0){ /* finds the best hole */
            a[i] = a[i-1];
            i--;
        }
        a[i] = key; /* fills the hole */
        
    }
}

int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;
    
    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }

    insertion_sort(
    
    /* print out the array of structs */
    
    for (i = 0; i < num_items; i++) {
        print_ocean_datum(&ocean_data[i]);
    }
    return EXIT_SUCCESS;
}
