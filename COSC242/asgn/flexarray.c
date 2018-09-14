#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   This file creates a structure called flexarray and all its functions to
   create, insert, sort, free and print all the words in held in the array
*/


/**creates an collection that consists of named members that hold values.
   capacity - the current maximum capacity of the array
   itemcount - the current amount of strings in the words array
   words - an array of strings that holds the values of the dictionary
*/
struct flexarrayrec {
    int capacity;
    int itemcount;
    char **words;
};

/**creates a new flex array of default size and sets default values
   @return - a pointer to the newly created flexarray structure
*/
flexarray flexarray_new() {
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->words = emalloc(f->capacity * sizeof f->words[0]);
    return f;
}
/* adds a new item to the flexarray and doubles the size if the maximum capacity
   is reached.
   @param f - a pointer to the flexarray structure to add the word to.
   @param newword - a pointer to the string to add to the array
*/
void flexarray_append(flexarray f, char *newword) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->words = erealloc(f->words, f->capacity * sizeof f->words[0]);
    }
    f->words[f->itemcount]=emalloc((strlen(newword)+1) * sizeof f->words[0]);
    strcpy(f->words[f->itemcount], newword);
    f->itemcount++;
}

/**frees the memory allocated to the flex array
   @param f - a pointer to the flexarray to free
*/
void flexarray_free(flexarray f) {
    int i;
    if(f==NULL){
        return;
    }
    for (i = 0; i < f->itemcount; i++){
        free(f->words[i]);
    }
    free(f->words);
    free(f);
}

/**returns whether a word is found when searching the list
   @param f - a pointer to the flexarray to search in
   @param word - a pointer to the string to search for in the array
   @return - an int representing true(1) or false(0) if the word is found.
*/
int is_present(flexarray f, char *word){
    int i = 0;
    if(f==NULL){
        return 0;
    }
    while (i < f->itemcount){
        if (strcmp(f->words[i], word)==0){
            return 1;

        }
        i++;
    }
    return 0;
}

/**prints each item in the flex array by sending a word to the function
   @param f - the flexarray to print words from
   @param word - the function sent from the container class to print a word
*/
void flexarray_visit(flexarray f, void p(char *word)){
    int n = 0;
    if(f==NULL){
        return;
    }
    while (n < f->itemcount){
        p(f->words[n]);
        n++;
    }
}

