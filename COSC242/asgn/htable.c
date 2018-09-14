#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "container.h"
#include "htable.h"

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
 * htable.c
 * creates a new htable to put elements to
 * calls to container functions to add and search elements in the htable
 */

/* converts strings to a corresponding int
   @param *word - char to convert to int
   @return unsigned int of the *word
*/
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

/* creates a struct
 */
struct htablerec {
    int capacity;
    int num_keys;
    container *keys;
};


/* creates a new hash table with RBT or flexarray types with capacity size
 * using the container_new function
 @param size - size of htable
 @return htable
*/
htable htable_new( int size){
    int i;
    htable h = emalloc(sizeof *h);
    h->capacity = size;
    h->num_keys = 0;
    h->keys = emalloc(h->capacity * sizeof h->keys[0]);
    for (i = 0; i < h->capacity; i++){
        h->keys[i] = NULL;
    }
    return h;
}

/* free memory space of the hash table
   @param h - htable to be freed
*/
void htable_free(htable h){
    int i;
    for(i=0; i<h->capacity; i++){
        container_free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}


/* calls to the container_add function
 * inserts words in the hash table using a single hash
 @param h htable to insert a new element to
 @param *str - element to add
 @param container_type - tells htable to use an RBT or a flexarray container
 @return if successful
*/
int htable_insert(htable h, char *str, int container_type){
    unsigned int hashing = htable_word_to_int(str);
    int index = hashing%h->capacity;
    if(h->keys[index]==NULL){
        h->keys[index] = container_new(container_type);
    }
    container_add(h->keys[index], str);
    h->num_keys ++;
    return 1;
}

/* calls to the container_print to print its contents
   @param h - htable to print
   @param *stream - place to print the htable to 
*/
void htable_print(htable h, FILE *stream){
    int i;
    for (i = 0; i < h->capacity; i++){
        if (h->keys[i] != NULL){
            printf("%i ", i);
            container_print(h->keys[i]);
            fprintf(stream, "\n");
        }
    }
}


/* calls to the container_search function to search for an element
   @param h - htable to search the element in
   @param *key - element to search for
   @return if successful
*/
int htable_search(htable h, char *key){
    unsigned int hashing = htable_word_to_int(key);
    int index = hashing%h->capacity;
    if(container_search(h->keys[index], key) != 0){
        return 1;
    }
    return 0;
}

















