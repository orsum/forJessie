#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "queue.h"

#define DEFAULT_CAPACITY 5

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new(){
    queue q = emalloc(sizeof *q);
    q->head = 0;
    q->capacity = DEFAULT_CAPACITY;
    q->num_items = 0;
    q->items = emalloc(q->capacity * sizeof q->items[0]);
    return q;
}

void enqueue(queue q, double item){
    if (q->num_items < q->capacity){
        int index = (q->head + q->num_items)%q->capacity;
        q->items[index] = item;
        q->num_items++;
    } else {
        printf("%f not added. Queue is full.\n", item);
    }
}

double dequeue(queue q){
    if (q->num_items > 0){
        double d = q->items[q->head];
        q->head = (q->head+1) % q->capacity;
        q->num_items--;
        return d;
    } else {
        printf("Queue is empty");
        return -1.0;
    }
}

void queue_print(queue q){
    int i = q->head;
    int count;
    for (count = q->num_items; 0 < count; count--){
        printf("%.1f\n", q->items[i]);
        i = (i+1)%q->capacity;
    }
}

int queue_size(queue q){
    return q->num_items;
}

queue queue_free(queue q){
    free(q->items);
    free(q);
    return q;
}
