#include <stdio.h>


#define HI "Program helps you to invert symbols to their ASCII codes or opposite;\n\nPlease choose working mode(type \'@\' to end):\n" //строка что выводится при запуске программы

int ch; //значение вводимое пользователем
void menu(); //функция для вывода сообщения главного меню

void main(void){

    printf("%s", HI);

    menu();

    while ((ch = getchar()) != '@')  //цикл для многоразового использования программы
    {   

        if (ch == '1'){     //первый режим работы программы
            printf("----------------------------------------------------------------------------");
            printf("\nInsert symbol or type \'#\' to exit to menu.\n");

            while ((ch = getchar()) != '#'){    //внутренний цикл режима
                ch == 10 ? printf("") : printf("\nASCII code of \'%c\' is %d.", ch, ch);    //трансформация символа в его код
            }
            
        }else if (ch == '2'){      //второй режим работы
            
            printf("----------------------------------------------------------------------------");
            printf("\nInsert ASCII code (<255) or type \'#\' to exit to menu.\n");

            while (scanf("%d", &ch)){       //getchar() тут не подойдет т.к. она считывает только один символ, а не число целиком
                printf("\nASCII %d is \'%c\'", ch, ch);  //трансформация кода символа непосредственно в символ
            }


        }else{ 
            (ch != '\n' || '#') ? printf("\n\n\aWrong mode!Try again.\n") : printf(""); //если выбран неверный режим
        }

        while (getchar() != '\n')   //так как символ новой строки остается в потоке ввода, getchar ошибочно считывает
        {
            continue;               //его, этот цикл пропускает все ненужные символы новой строки очищая поток для
        }                           //следущей функции getchar()

        //printf("|\'%c\'|", ch); //для теста ввода
        ch != '\n' ? menu() : printf(""); //вывод меню лучше всего писать в конце цикла, до if-ов
        
    }

    printf("Closing program...");

    getchar();      //на всякий чтобы программа не закрывалась аросто так
    getchar();
}

void menu(void){ 
    printf("\nMain menu.\nProgram have two working modes:");
    printf("\n\n1) You can get ASCII code from the symbol");
    printf("\n2) You can turn ASCII code into a symbol");
    printf("\nTo close the program simply type \'@\'");
}