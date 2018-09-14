#ifndef CONTAINER_H_
#define CONTAINER_H_

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   Header file for container.c
*/

/**defines a pointer to a containerrec structure to be called container
 */
typedef struct containerrec *container;

/**an enum type of container- either flexarray or red black tree -
   called container_t.
*/
typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;


/**adds a new word to either container type
   @param c - a pointer to the container to be added to
   @param word - the word to add to the container
*/
extern void      container_add(container c, char *word);

/**frees the allocated memory of the container when it isnt needed anymore
   @param c - a pointer to the container to be freed
   @return the newly freed container
*/
extern container container_free(container c);

/**creates a new container of the requested type
   @param c - a pointer to the container to be created 
   @return the newly created container
*/
extern container container_new(int t);

/**searches the container for the requested word
   @param c - a pointer to the container to be created
   @param str - the string to be searched for
   @return an int value for true(1) or false(0) if the word has been found
*/
extern int       container_search(container c, char *str);

/**prints all the words in the container on one line
   @param c - a pointer to the container to be created 
*/
extern void      container_print(container c);

#endif
