#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"

/* Allocates memory space of a give size and returns it if successful*/
void *emalloc(size_t s) {
    
    void *p = malloc(s);
    if (p == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

/* Allocates more space for an array, called if an array is at capacity and
 needs to be expanded*/
void *erealloc(void *p, size_t s) {
    
    p = realloc(p, s);
    if (p == NULL){
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

/* merges two sorted arrays into one array (a = new array, w = workspace, l = length of the array together).  Used with mergesort*/
void merge (int *a, int *w, int l){
    int i, j, k;
    i = 0;
    j = (l/2);
    k = 0;
    while (i < l/2 && j < l){
        if (a[i] < a[j]){
            w[k] = a[i];
            i++;
        } else{
            w[k] = a[j];
            j++;
        }
        k++;
    }
    if (i >= l/2){
        for (; j < l ; j++){
            w[k] = a[j];
            k++;
        }
    } else {
        for (; i < l/2; i++){
            w[k] = a[i];
            k++;
        }
    }
    return;
}

/* sorts an array by taking one item and inserting it in the correct place in
   the group of already sorted elements. */
void insertion_sort(int *a, int n) {
    int p;
    int key;
    int i;
    for (p = 1; p < n; p++){
        key = a[p]; 
        i = p;
        while (key < a[i-1] && i > 0){ 
            a[i] = a[i-1];
            i--;
        }
        a[i] = key;
    }
}

/* takes an array, a workspace the size of the array and the length of the current part of the array and sorts it using a merge sort and insertion sort when segments are small enough.
 */
void merge_sort(int *a, int *w, int l) {
    int mid, i;
    if (l < 2){
        return;
    }
    if (l <= 40){
        insertion_sort(a, l);
    } else {
        mid = l/2;
        merge_sort(a, w, mid);
        merge_sort(a + mid, w, l - mid);
        merge(a, w, l);
        for (i = 0; i < l; i++){
            a[i] = w[i];
        }
    }
}


