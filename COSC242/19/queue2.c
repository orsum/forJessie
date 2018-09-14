#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "queue.h"

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new(){
    queue q = emalloc(sizeof (*q));
    return q;
}

void enqueue(queue q, double item){
    q_item i = emalloc(sizeof (*i));
    i->item = item;
    if(q->length == 0){
        q->first = i;
        q->last = i;
    } else {
        q->last->next = i;
        q->last = i;
    }
    q->length++;
}

double dequeue(queue q){
    double d = q->first->item;
    q_item i = q->first;
    if (q->first->next != NULL){
        q->first = q->first->next;
    } else {
        q->first = NULL;
    }
    q->length--;
    free(i);
    return d;
}

void queue_print(queue q){
    q_item p = q->first;
    while (p != NULL){
        printf("%.1f\n", p->item);
        p = p->next;
    } 
}
int queue_size(queue q){
    return q->length;
}

queue queue_free(queue q){
    q_item temp;
    while (q->length > 0){
        q->length--;
        temp = q->first;
        q->first = q->first->next;
        free(temp);
    }
    free(q);
    return q;
}
