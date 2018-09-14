#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 30000


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

int main(void){

    int my_array[ARRAY_MAX];
    int i;

    /*
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
        }*/

    my_array[0] = 1;
    my_array[1] = 2;
    my_array[2] = 3;
    my_array[3] = 4;
    my_array[4] = 5;
    my_array[5] = 6;
    my_array[6] = 7;
    my_array[7] = 8;
    my_array[8] = 9;
    my_array[9] = 10;
    
    for(i = 0; i <= 11; i++){
        printf("%d? %d\n", i, binary_search(i, 10, my_array));
    }

    return EXIT_SUCCESS;

}
    
