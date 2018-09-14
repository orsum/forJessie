#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_MAX 10000
#define STRING_LEN 50

/* Ali Morris 25 July 2017 Lab 5*/

/* Method takes an array and the length of that array and sorts it to ascending
   order by taking one item and putting it into the correct place in the already
   sorted items..
   Parameters: a: pointer to the dictionary array
*/
void insertion_sort(char **a, int n) {
    int p;
    char *key;
    int i;
    
    for (p = 1; p < n; p++){
        key = a[p]; /* saves the one to compare */
        i = p;
        while (i > 0 && strcmp(key, a[i-1]) < 0){ /* finds the best hole */
            a[i] = a[i-1];
            i--;
        }
        a[i] = key; /* fills the hole */
        
    }
}

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/* main method that creates an array, and times the insertion sort*/
int main(void) {
    char word[STRING_LEN];
    char *word_list[ARRAY_MAX];
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%s", word)) {
        word_list[count] = emalloc((strlen(word) + 1) * sizeof word_list[0][0]);
        strcpy(word_list[count], word);
        count++;
    }

    insertion_sort(word_list, count);
    
    for (i = 0; i < count; i++) {
        printf("%s\n", word_list[i]);
    }
    
    return EXIT_SUCCESS;
}
