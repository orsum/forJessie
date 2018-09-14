#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void merge_sort(int *a, int *w, int n) {
    if (n < 2){
        return;
    }
    int mid = n/2;
    merge_sort(a, w, 
    
    /* take care of stopping condition first
    if the array to be sorted has fewer than two elements then return
               call merge_sort on the first half of array a
               call merge_sort on the second half of array a
               merge the two halves of array a into array w
               copy array w back into array a
    */

    
}
int main(void) {
    
    int my_array[ARRAY_MAX];
    
    clock_t start, end;
    
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }
    
    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    
    return EXIT_SUCCESS;
}
