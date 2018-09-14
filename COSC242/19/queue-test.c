#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "queue.h"

int main(void){
    double item;

    queue q = queue_new();
    
    while (1 == scanf("%lf", &item)){
        enqueue(q, item);
    }

    queue_print(q);

    while(queue_size(q) > 0){
        printf("\n%.1f", dequeue(q));
    }

    q = queue_free(q);
    
    return EXIT_SUCCESS;
}
