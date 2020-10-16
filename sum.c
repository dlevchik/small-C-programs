#include <stdio.h>

#define HI "Program helps you to calculate sum of numbers from a to b.\nPLS insert First number:\n"

int a, b;
int sumFunction(int x, int y);

void main(void){

    printf("%s", HI);
    scanf("%d", &a);

    while (a > 0)
    {
        printf("\nAnd a second number:");
        scanf("%d", &b);

        printf("\nYour sum is %d",sumFunction(a, b));

        printf("\n\nYou can type 0 to close program or insert new numbers to calculate:");
        scanf("%d", &a);
    }
    printf("\nClosing program...");

    getchar();
    getchar();
}

int sumFunction(int x, int y){
    int sumNum = 0;

    while (x <= y )
    {
        sumNum = sumNum + x;

        printf("%5d", x);
        ++x;
    }
    
    return sumNum;
}