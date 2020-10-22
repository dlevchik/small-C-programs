//TODO: process negative numbers

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define HI "Program helps you to convert digits to binary or binary to digit.\n\nPlease choose working mode: \n1) Digit to binary; \n2) Binary to digit\n(\'/q\' to quit)"
#define CH_SIZE 3
#define INPUT_SIZE 15

char * getFunc(char * str, int n);
int check(char const * const str, const int n, bool isBinary);
char * toBinary(const char const * str, char * output);
long int toNum(const char const * str);

void wait(void){
    printf("\n\nPress any key to continue...");

    char gh[6];
    getFunc(gh, 6);
    system("cls");
}

int main(void){
    bool run = true;
    char ch[CH_SIZE];
    char input[INPUT_SIZE];
    int chk;

    while (run)
    {   
        system("cls");
        printf("%s", HI);
        getFunc(ch, CH_SIZE);

        if (strncmp(ch, "/q", CH_SIZE) == 0)
        {
            run = false;
        }
        
        switch (ch[0])
        {
            case '1':
                system("cls");
                printf("Insert digit you want to convert to binary or type \'/q\' to cancel:");

                while (1)
                {   
                    do
                    {
                        getFunc(input, INPUT_SIZE);
                        chk = check(input, INPUT_SIZE, false);
                    } while (chk == 0 && chk != -1);
    
                    if(chk == -1){
                        break;
                    }
                
                    char * code;

                    printf("\nBinary code of %s: 0x%s;", input, toBinary(input, code));
                    free(code);
                }
            break;

            case '2':
                system("cls");
                printf("Insert code you want to convert to digit or type \'/q\' to cancel:");

                while (1)
                {   
                    do
                    {
                        getFunc(input, INPUT_SIZE);
                        chk = check(input, INPUT_SIZE, true);
                    } while (chk == 0 && chk != -1);
    
                    if(chk == -1){
                        break;
                    }

                    printf("Code 0x%s is %ld;", input, toNum(input));
                }
            break;
            
            default:
                system("cls");
                printf("Incorrect input, please try again!\n\n");
            break;
        }
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

int check(char const * const str, const int n, const bool isBinary){
    if (str[0] == '\0')
    {
        printf("\nInput can\'t be blank. Try again:");
        return 0;
    }

    if (strncmp(str, "/q", CH_SIZE) == 0)
    {
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
        
        if (isBinary && !(str[i] == '0' || str[i] == '1'))
        {
            printf("\nBinary code must contain only 0 or 1. Please try again:");
            return 0;
        }

        if (!isdigit(str[i]))
        {
            printf("\nNumber must contain only digits. Please try again:");
            return 0;
        }
    }

    return 1;
}

char * toBinary(const char const * str, char * output){
    long int num = atoi(str);
    int i = 1;

    char * result = (char*) malloc(sizeof(char) * 1);
    if (!result){
        fprintf(stdout, "malloc ERROR;");
        exit(EXIT_FAILURE);
    }

    do
    {   
        ++i; 

        result = (char*) realloc(result, sizeof(char) * i);
        if (!result){
            fprintf(stdout, "realloc ERROR;");
            exit(EXIT_FAILURE);
        }
       
        if (num % 2)
        {
            result[i-2] = '1';
        } else
        {
            result[i-2] = '0';
        }

        num = num / 2;
    } while (num != 0);
    
    output = malloc(sizeof(char) * i);
    if (!output){
        fprintf(stdout, "malloc ERROR;");
        exit(EXIT_FAILURE);
    }

    for (int j = 0, x = i - 2; j < i - 1; j++, x--)
    {   
        output[j] = result[x];
    }
   
    output[i-1] = '\0';
   
    free(result);
    return output;
}

long int toNum(const char const * str){
    long int result = 0;

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            result += powl(2, strlen(str) - i - 1);
        }
    }
    
    return result;
}