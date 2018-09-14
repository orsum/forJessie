#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* Ali Morris 21 July 17 Lab 4*/

/* Method takes an array and the length of that array and sorts it to ascending
   order by finding the smallest of a subarray and swapping it to the start of
   that array.
 */
void selection_sort(int *a, int n) {
    int p, j, temp;
    j = 0;
    while (j < n-1){
        int smallest_index;
        smallest_index = j;
        for (p = j; p < n; p++){ /* iterates through the subarray */
            if (a[smallest_index] > a[p]){ /* finds the smallest */
                smallest_index = p;
            }
        }
        temp = a[j]; /* swaps the smallest with the first */
        a[j] = a[smallest_index];
        a[smallest_index] = temp;
        j++;
        smallest_index = j;
    }
}

/* main method that creates an array, and times the selection sort*/
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    selection_sort(my_array, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
