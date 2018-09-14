#ifndef MYLIB_H_
#define MYLIB_H_

#include <stdio.h>
#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern void merge (int *a, int *w, int l);
extern void insertion_sort(int *a, int n);
extern void merge_sort(int *a, int *w, int l);
extern void quick_sort(int *a, int l);
extern int getword(char *s, int limit, FILE *stream);

#endif
