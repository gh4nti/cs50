#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    float dollars;

    do{
        dollars = get_float("Change owed (in dollars): ");
    }
    while(dollars < 0);
    int x = round(dollars * 100);
    int n = 0; // Number of coins
    int y = x; // Change owed

    while(y >= 25){
        y = y - 25;
        n++;
    }

    while(y >= 10 && y < 25){
        y = y - 10;
        n++;
    }

    while(y >= 5 && y < 10){
        y = y - 5;
        n++;
    }

    while(y >= 1 && y < 5){
        y = y - 1;
        n++;
    }
    printf("%i\n", n);
}