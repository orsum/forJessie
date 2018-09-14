#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int count = 0;
    double judge1[10], judge2[10], judge3[10];
    while(4 == scanf("%d%lg%lg%lg",&n,&judge1[count],&judge2[count],
                     &judge3[count])){
        count++;
    }
    double judge1_average = 0;
    double judge2_average = 0;
    double judge3_average = 0;
    for(n = 0; n < count; n++){
        judge1_average += judge1[count];
    }
    for(n = 0; n < count; n++){
        judge2_average += judge2[count];
    }
    for(n = 0; n < count; n++){
        judge3_average += judge2[count];
    }
    judge1_average = judge1_average / (double)count;
    judge2_average = judge2_average / (double)count;
    judge3_average = judge3_average / (double)count;
    double jud
    return EXIT_SUCCESS;
}
