#include <stdio.h>
#include <stdlib.h>


#define ARRAY_MAX 100000

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

void merge_sort(int *a, int *w, int l) {
    int mid, i;
    if (l < 2){
        return;
    }
    mid = l/2;
    merge_sort(a, w, mid);
    merge_sort(a + mid, w, l - mid);
    merge(a, w, l);
    for (i = 0; i < l; i++){
        a[i] = w[i];
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
    
    int a[ARRAY_MAX];
    int w[ARRAY_MAX];
   
    
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &a[count])) {
        count++;
    }
    
    
    
    merge_sort(a, w, count);
    
    
    for (i = 0; i < count; i++) {
        printf("%d\n", a[i]);
    }
    
    
    
    return EXIT_SUCCESS;
}
