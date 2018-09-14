#include <stdio.h>
#include <stdlib.h>

int main (void){
    int n, winner;
    double a, b, c, win_score;
    win_score = 0;
    winner = 0;

    while (4 == scanf("%d%lg%lg%lg", &n, &a, &b, &c)){
        if (a <=b && a <= c) {
            if(((b + c) / 2) > win_score){
                winner = n;
                win_score = ((c + b) / 2);
            }
        } else if (b <= a && b <= c) {
            if(((a + c) / 2) > win_score){
                winner = n;
                win_score = ((a + c) / 2);
            }
        } else {
            if(((a + b) / 2) > win_score){
                winner = n;
                win_score = ((b + a) / 2);
            }
        }
    }
    printf("%d\n", winner);
    return EXIT_SUCCESS;
}
