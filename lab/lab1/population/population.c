#include <stdio.h>
#include <cs50.h>

int main(void){
    int n1, n2;

    // Prompt user for start size
    do{
        n1 = get_int("Start size: ");
    }
    while(n1 < 9);

    // Prompt user for end size
    do{
        n2 = get_int("End size: ");
    }
    while(n2 < n1);

    int n = 0; // Number of years

    while(n1 <= n2){
        n1 = n1 + (n1 / 3) - (n1 / 4);
        n++;

        if(n1 == n2){
            break;
        }
    }

    printf("Years: %i\n", n);
}