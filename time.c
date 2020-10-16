#include <stdio.h>

#define HI "Program helps you to invert time in seconds to hours, minutes and seconts format.\nPLS insert time in seconds here:\n"
#define COEF 60

int seconds;
float minutes, hours;

void main(void){

    printf("%s", HI);

    scanf("%d", &seconds);

    while (seconds > 0)
    {
        minutes = (float) seconds / COEF;
        hours = (float) seconds / 3600;

        minutes = (int) minutes % 60;
        seconds = seconds % 60;

        printf("\nHours Minutes Seconds\n%5d %7d %7d\n", (int) hours, (int) minutes, seconds);

        printf("\nYou can insert new value to calculate  or type 0 to close program:\n");
        scanf("%d", &seconds);

    }
    printf("Closing program...");

    getchar();
    getchar();
}