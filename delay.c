#include <stdio.h>
#include <time.h>
#define ITERATIONS 30
#define DELAY 1100

void delay(const long int ms);

int main(int argc, char const *argv[])
{

    for (int i = 0; i <= ITERATIONS; i++)
    {
        printf("Delay(%dms) iteration: %d/%d; Time from start of the program: %ds\n", DELAY, i, ITERATIONS, (clock()/CLK_TCK));
        delay(DELAY);
    }
    

    getchar();
    getchar();
    return 0;
}

void delay(const long int ms){
    long double timeTo = ((long double) clock())/CLK_TCK + ((long double) ms)/CLK_TCK;

    while (((long double) clock()/CLK_TCK) <= timeTo)
    {
        ;
    }
    
}
