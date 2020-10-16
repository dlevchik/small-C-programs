#include <stdio.h>
#include <ctype.h>

#define HI "Program helps you to cout literally every symbol;\n\nInsert some text you want to count symbols on:\n" //строка что выводится при запуске программы
#define SIZE 256    //размер массива 
#define COLUMS 10      //сколько значений будут отображаться в таблице результатов(табуляция)

int ch;     //значение вводимое пользователем/найденое в файле
long int allCharCount;         //количество всех символов в файле
long int charsArray[SIZE];      //непосредственно масив всех символов встречаемых в файле
int iterations;         //успешные выполнения цикла, нужно для табуляции

void main(void){

    printf("%s", HI); //вывод приветственного сообщения

   while ((ch = getchar()) != EOF){     //пока не достигнут конец файла(или комбинация Ctrl+Z)
       if(!isspace(ch)){
           ++allCharCount;      //пропускать пробелы в подсчете общего числа символов
       }
       ++charsArray[(int) ch];      //запись результата в массив
   }

   printf("All chars count: %ld; \nDetailed results:\n", allCharCount);
   
    for (int i = 0; i < SIZE ; i++){        //цикл прохождения по массиву
        if (charsArray[i] == 0){
            continue;           //если значения нет пропустить итерацию
        }

        if((iterations % COLUMS) == 0){         //для табуляции таблицы результатов(а то некрасиво как-то)
            printf("\n");
        }

        i == 10 ? printf("\'\\n\': %ld; ", charsArray[i]) : printf("\'%c\': %ld; ", i, charsArray[i]);          //вывод результата
        ++iterations;        //инкреманция переменной для табуляции
    }

    printf("\nClosing program...");

    getchar();      //на всякий чтобы программа не закрывалась просто так
    getchar();
}