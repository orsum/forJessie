#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   This file is the header file for flexarray.c.
*/

/** Defines a structure flexarrayrec to have the name flexarray */
typedef struct flexarrayrec *flexarray;

/* adds a new item to the flexarray and doubles the size if the maximum capacity
   is reached.
   @param f - a pointer to the flexarray structure to add the word to.
   @param newword - a pointer to the string to add to the array
*/
extern void      flexarray_append(flexarray f, char *word);

/**frees the memory allocated to the flex array
   @param f - a pointer to the flexarray to free
*/
extern void      flexarray_free(flexarray f);

/**creates a new flex array of default size and sets default values
   @return - a pointer to the newly created flexarray structure
*/
extern flexarray flexarray_new();

/**returns whether a word is found when searching the list
   @param f - a pointer to the flexarray to search in
   @param word - a pointer to the string to search for in the array
   @return - an int representing true(1) or false(0) if the word is found.
*/
extern int       is_present(flexarray f, char *word);

/**prints each item in the flex array by sending a word to the function
   @param f - the flexarray to print words from
   @param word - the function sent from the container class to print a word
*/
extern void      flexarray_visit(flexarray f, void p(char *array));

#endif
