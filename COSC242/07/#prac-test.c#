#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 100

void *emalloc(size_t s) {

    void *result = malloc(s);

    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

void long_words(char **wordlist, double average, int num_words){
    if (num_words == 0){
        return;
    } else if (strlen(wordlist[0]) > average){
        printf("%s\n", wordlist[0]);
    }
    long_words(wordlist + 1, average, num_words -1);
}
        

int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    double average;
    int i;

    num_words = 0;

    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words]=emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    if (num_words != 0){
        average = 0.00;
        for (i = 0; i < num_words; i++) {
            average += strlen(wordlist[i]);
        }
    
        average = average / num_words;

        long_words(wordlist, average, num_words);
    
        fprintf(stderr, "%.2f\n", average);

    
        for (i = 0; i < num_words; i++) {
            free(wordlist[i]);
        }
    }
    return EXIT_SUCCESS;
}
