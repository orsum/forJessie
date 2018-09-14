#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"
#include "queue.h"

/**
   struct to hold all the attributes of the items in the queue
*/
struct q_item {
    int item;
    q_item next;
};

/**
   struct to hold the items in the queue
*/
struct queue {
    q_item first;
    q_item last;
    int length;
};

/**
   creates a new instance of queue
   @return the new queue
*/
queue queue_new(){
    queue q = emalloc(sizeof (*q));
    q->length = 0;
    q->first = NULL;
    q->last = NULL;
    return q;
}

/**
   adds an item to the back of the queue
   @param q - the queue to be added to
   @param item - the value to be added to the item
*/
void enqueue(queue q, int item){
    q_item i = emalloc(sizeof (*i));
    i->item = item;
    i->next = NULL;
    if(q->length == 0){
        q->first = i;
        q->last = i;
    } else {
        q->last->next = i;
        q->last = i;
    }
    q->length++;
}

/**
   removes an item from the front of the queue
   @param q - the queue to remove the item from
   @return the value of the item that was removed
*/
int dequeue(queue q){
    int d = q->first->item;
    q_item i = q->first;
    if (q->first != NULL){
        if (q->first->next != NULL){
            q->first = q->first->next;
        } else {
            q->first = NULL;
        }
    q->length--;
    }
    free(i);
    return d;
}

/**
   prints the queue in order
   @param q - the queue to be printed
*/
void queue_print(queue q){
    q_item p = q->first;
    while (p != NULL){
        printf("%d\n", p->item);
        p = p->next;
    } 
}

/**
  returns the current size of the queue
  @param q the queue to be calculated
  @return the size oft he queue
*/
int queue_size(queue q){
    return q->length;
}

/**
   frees any  memory allocated to the queue and its items
   @param q- the queue to be freed
   @return null
*/
queue queue_free(queue q){
    q_item temp;
    while (q->length > 0){
        q->length--;
        temp = q->first;
        q->first = q->first->next;
        free(temp);
    }
    free(q);
    return NULL;
}
