#include <stdio.h>
#include <stdlib.h>

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
    }
}

void print_array(int *a, int n){
    if (n > 0){
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

/* main method that creates an array, and times the insertion sort*/
int main(void) {
    int my_array[ARRAY_MAX];
    int count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    insertion_sort(my_array, count);
    
    print_array(my_array, count);
    
    return EXIT_SUCCESS;
}