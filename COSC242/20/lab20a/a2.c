#include <stdlib.h>
#include <stdio.h>

int is_prime(int c){
    int i;
    for (i = 2; i < c; i++){
        if (c % n == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int c = 2;
    int count = 0;
    while (count < 200){
        if (is_prime(c) < 1){
            printf("%5d", c);
            count++;
        
            if (count%10 == 0){
                printf("\n");
            }
        }
        c++;
    }
}
