#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 2000000

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
    
    
    
    /* take care of stopping condition first
    if the array to be sorted has fewer than two elements then return
               call merge_sort on the first half of array a
               call merge_sort on the second half of array a
               merge the two halves of array a into array w
               copy array w back into array a
    */


int main(void) {
    
    int *a;
    int *w;
    clock_t start, end;
    
    int i, count = 0;

    a = malloc(ARRAY_MAX * sizeof a[0]);
    if (NULL == a) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    w = malloc(ARRAY_MAX * sizeof a[0]);
    if (NULL == w) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &a[count])) {
        count++;
    }
    
    
    start = clock();
    merge_sort(a, w, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%i\n", a[i]);
    }
    
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);

    free(a);
    free(w);
    
    return EXIT_SUCCESS;
}