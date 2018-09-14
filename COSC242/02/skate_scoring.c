#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    double s1, s2, s3;
    while(!feof(stdin)){
        scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3);
        printf("Competitor: %d Score: ", n);
        if (s1 < s2 && s1 < s3) {
            printf("%f\n", (s2+s3)/2);
        } else if (s2 < s1 && s2 < s3) {
            printf("%f\n", (s1+s3)/2);
        } else if (s3 < s2 && s3 < s1) {
            printf("%f\n", (s2+s1)/2);
        }
    }
    return EXIT_SUCCESS;
}
    
