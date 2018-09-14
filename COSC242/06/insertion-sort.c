#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* Ali Morris 21 July 17 Lab 4*/

/* Method takes an array and the length of that array and sorts it to ascending
   order by taking one item and putting it into the correct place in the already
   sorted items..
*/
void insertion_sort(int *a, int n) {
    int p;
    int key;
    int i;
    for (p = 1; p < n; p++){
        key = a[p]; /* saves the one to compare */
        i = p;
        while (key < a[i-1] && i > 0){ /* finds the best hole */
            a[i] = a[i-1];
            i--;
        }
        a[i] = key; /* fills the hole */
        
        /*alternately:
          while (key < a[i-1]){
            int temp = a[i-1];
            a[i-1] = a[i];
            a[i] = temp;
            i--;
        }
        */
    }
}

/* main method that creates an array, and times the insertion sort*/
int main(void) {
    int my_array[ARRAY_MAX];
   
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
