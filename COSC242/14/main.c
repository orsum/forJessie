#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "bst.h"

void print_key(char *s) {
    printf("%s\n", s);
}

int main(void) {
    bst b = bst_new();
    b = bst_insert(b, "H");
    b = bst_insert(b, "D");
    b = bst_insert(b, "L");
    b = bst_insert(b, "B");
    b = bst_insert(b, "F");
    b = bst_insert(b, "J");
    b = bst_insert(b, "N");
    b = bst_insert(b, "A");
    b = bst_insert(b, "C");
    b = bst_insert(b, "E");
    b = bst_insert(b, "G");
    b = bst_insert(b, "I");
    b = bst_insert(b, "K");
    b = bst_insert(b, "M");
    b = bst_insert(b, "O");

    b = bst_delete(b, "D");
    b = bst_delete(b, "M");
    b = bst_delete(b, "N");

    printf("%i\n", bst_search(b, "D"));
    printf("%i\n", bst_search(b, "A"));
    
    bst_inorder(b, print_key);

    bst_free(b);

    return EXIT_SUCCESS;
}
