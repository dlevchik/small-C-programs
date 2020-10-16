#include <stdio.h>

#define HI "Program helps you to output a cool pyramid made from chars\n\nPlease insert some char:\n" //строка что выводится при запуске программы
#define A_ASCII 65 //код первого символа в АSCII

int rows; //код буквы вводимый пользователем

void main(void){

    printf("%s", HI);

    while (scanf("%c", &rows) == 1)  //цикл для многоразового использования программы
    {   
        printf("\n");

        for (int i = A_ASCII; i <= rows; i++) //цикл для табуляции
        {
            for (int j = A_ASCII; j <= (rows - (i - A_ASCII)); j++) //цикл для пробелов
            {
                printf("%c", 32);
            }

            for (int j = A_ASCII; j <= i; j++) //цикл для вывода букв в возрвстающем порядке
            {
                printf("%c", j);
            }

            for (int j = i - 1; j >= A_ASCII; j--) //цикл для вывода букв в убывающем порядке
            {
                printf("%c", j);
            }
            
            printf("\n");
        }
        
        printf("\nYou can type 0 to close program or insert new number of rows:"); //это не работает


    }

    getchar();
    getchar();
}