#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10000

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

int binary_search(int target, int length, int *a){
    int mid;
    if (length == 0){
        return 0;
    }
    mid = length/2;
    if (a[mid] == target){
        return 1;
    }
    else if(a[mid] > target){
        return binary_search(target, mid, a);
    }
    else if(a[mid] < target){
        return binary_search(target, length-(mid+1), a+mid+1);
    }
    return 0;
}


int main(int argc, char **argv) {
    FILE *data;
    int my_array[ARRAY_MAX];
    int count, target;
    char x;

    
    if(NULL == (data = fopen(argv[1], "r"))){
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    count = 0;
    while (1 == fscanf(data, "%d", &my_array[count])) {
        count++;
    }
  
    fclose(data);

    insertion_sort(my_array, count);

    while(1 == scanf("%d", &target)){
        x = binary_search(target, count, my_array) == 1 ? '+' : '-';
        printf("%c\n", x);
    }

    return EXIT_SUCCESS;
}
