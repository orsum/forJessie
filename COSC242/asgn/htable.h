#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>
#include "container.h"

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   header for htable.c
*/

/* struct of htablerec defined in the htable.c*/
typedef struct htablerec *htable;

/*creates a new htable
  @param container_type - type either RBT or a flexarray
  @param size - size of the htable
  @return htable
*/
extern htable htable_new( int size);

/* free used memory by the htable
   @param h - htable to be freed*/
extern void htable_free(htable h);

/* inserts a new element in the htable
   @param h - htable to insert element to
   @param *str - pointer to the element to be put in
   @return check if insert is successful*/
extern int htable_insert(htable h, char *str, int container_type);

/* calls on the container_ print function to print its contents
   @param h - htable to print
   @param *stream - place to print the htable to*/
extern void htable_print(htable h, FILE *stream);

/* calls on the container_search function to search the contents for *key
   @param h - htable to search
   @param *key - element to search for
   @return if successful
*/
extern int htable_search(htable h, char *key);


#endif /* htable_h */






