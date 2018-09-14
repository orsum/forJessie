#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>

/**@author Ali Morris, Abigail Tubay, Chenyang Zhang
   header for mylib.c
*/

extern int getword(char *s, int limit, FILE *stream);
extern void *emalloc(size_t s);
extern void *erealloc(void *p, size_t s);

#endif /* mylib_h */
