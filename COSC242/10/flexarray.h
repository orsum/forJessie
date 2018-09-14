#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern void      flexarray_append(flexarray f, char *word);
extern void      flexarray_free(flexarray f);
extern flexarray flexarray_new();
extern void      flexarray_print(flexarray f);
extern void      flexarray_sort(flexarray f);
extern char *    is_present(flexarray f, char *item);
extern flexarray visit(char *word);

#endif
