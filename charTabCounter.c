#include <stdio.h>
#include <ctype.h>

#define HI "Program helps you to count number of space symbols, tabs and  other symbols.\n\nPlease insert some chars(type \'#\' to end):\n" //строка что выводится при запуске программы

int ch; //значение вводимое пользователем
int symbols; //чтосло обычных симболов
int tabs; //число симболов табуляции
int spaces; //число отступов

void main(void){

    printf("%s", HI);

    while ((ch = getchar()) != '@')  //цикл для многоразового использования программы
    {   
        if (ch == '#') //завершение одного цикла
        {
            printf("\nsymbols| tabs |spaces\n");            //вывод обработаных значений
            printf("%7d|%6d|%6d", symbols, --tabs, spaces);

            symbols = 0;
            tabs = 0;           //обнуление переменных
            spaces = 0;

            printf("\n\nYou can insert new chars or type \'@\' to close the program."); //если нужно закрыть программу
        }
        else
        {
            switch (ch) //обработка входимых символов
            {
            case ' ':
                ++spaces;
            break;
            
            case '\n':
            case '\t':
                ++tabs;
            break;

            default:
                ++symbols;
                break;
            }
        }
    }

    printf("Closing program...");

    getchar();
    getchar();
}