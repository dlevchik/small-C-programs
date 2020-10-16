#include <stdio.h>

#define HI "Program helps you to change some symbols in text;\n\nFirstly insert symbol which will be changed:\n" //строка что выводится при запуске программы

int ch; //значение вводимое пользователем
int changable; //символ который будет заменен
int changeTo; //символ которым заменяют

void main(void){

    printf("%s", HI);
    changable = getchar(); //считывание заменяемого символа

    while (getchar() != '\n')   //так как символ новой строки остается в потоке ввода getchar ошибочно считывает
    {
        continue;               //его, этот цикл пропускает все не нужные символы новой строки очищая поток для
    }                           //следущей функции getchar()
    

    printf("\nGreat, now isert symbol to what it will be changed:");
    changeTo = getchar();
    
    printf("\nSo we will change \'%c\' to \'%c\'. Now you can insert text to process (or type \'#\' to end progam)", changable, changeTo);

    while ((ch = getchar()) != '#')  //цикл для многоразового использования программы
    {   
        ch == changable ? putchar(changeTo) : putchar(ch); //замена символа
    }

    printf("Closing program...");

    getchar();      //на всякий чтобы программа не закрывалась аросто так
    getchar();
}