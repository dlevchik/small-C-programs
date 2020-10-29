#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define HI "Perimeter.c\nThis program help's you to calculate perimeter of rectangle.\n"
#define INPUT_SIZE 6

char * getFunc(char * str, int n);
int check(char const * const str, const int n);

int main(void)
{
    int run = 1;
    char input[INPUT_SIZE];
    int operandA, operandB;

    printf("%s", HI);

    while(run){
        printf("\nPlease insert first side of rectangle(or type \'/q\' to quit program): ");

        do
        {
            getFunc(input, INPUT_SIZE);
            operandA = check(input, INPUT_SIZE);
        } while (operandA == 0);

        if (operandA == -1)
        {
            return 0;
        }

        printf("\nNow insert second side of rectangle(or type \'/q\' to quit program): ");

        do
        {
            getFunc(input, INPUT_SIZE);
            operandB = check(input, INPUT_SIZE);
        } while (operandB == 0);

        if (operandB == -1)
        {
            return 0;
        }

        printf("\nRectangle perimeter is %d\n", (2*operandA + 2*operandB));
    }
}

char * getFunc(char * str, int n){
    char * result;
    int i = 0;

    result = fgets(str, n, stdin);

    if(result){
        while (str[i] != '\n' && str[i] != '\0')
        {
            i++;
        }

        if(str[i] == '\n'){
            str[i] = '\0';
        } else{
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return result;
}

int check(char const * const str, const int n){
    int num;

    if (str[0] == '\0')
    {
        printf("\nInput can\'t be blank. Try again:");
        return 0;
    }

    if (strncmp(str, "/q", 3) == 0)
    {
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }

        if (!isdigit(str[i]) && str[i] != '-')
        {
            printf("\nInput must contain only digits. Please try again:");
            return 0;
        }

        num = atoi(str);

        if(num <= 0){
            printf("\nInput can\'t be negative number or 0. Please try again:");
            return 0;
        }
    }

    return num;
}

