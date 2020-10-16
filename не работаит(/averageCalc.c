#include <stdio.h>
#include <ctype.h>

#define HI "Program helps you to count number of specific numbers.\n\nPlease insert some numbers(type \'0\' to end):\n" //строка что выводится при запуске программы

int ch; //значение вводимое пользователем
int odd; //общее значение непарных чисел
int oddC; //количество непарных чисел
int even; //общее значение парных чисел
int evenC; //количество парных чисел
int allNum; //общее количество чисел
int numAver; //значение всех чисел

void main(void){

    printf("%s", HI);

    while ((ch = getchar()) != '@')  //цикл для многоразового использования программы
    {   
        if (ch == '0') //завершение одного цикла
        {
            if (oddC || evenC){     //проверка наличия данных
                
                printf("\n   all   | average | odd nums |odd average| even nums |even average\n");            //вывод обработаных значений
                //момент до которого доходит выполнение программы и она зависает, не знаю в чём может быть
                //причина
                printf("%9d|%9d|%10d|%11.1f|%11d|%12.1f", allNum, (numAver / allNum), oddC, (odd / oddC), evenC, (even / evenC));

                odd = 0;
                oddC = 0;           //обнуление переменных
                even = 0;
                evenC = 0;
                allNum = 0;
                numAver = 0;

                printf("\n\nYou can insert new numbers or type \'@\' to close the program."); //если нужно закрыть программу
            } else{                 //в случае если ничего не введено
                printf("Error: no numbers inserted, please try again.\n");
            }
            
        } else{   
            if(isdigit(ch) && ch != ' ' && ch != '\t' && ch != '\n'){ //точно ли это число?

                if (ch % 2 == 0){
                    ++even;         //увеличиваем счетчик
                    evenC += ch;    //добавляем число в кучу

                    ++allNum;
                    numAver += ch;
                }else if (ch % 2 != 0){
                    ++even;
                    evenC += ch;

                    ++allNum;
                    numAver += ch;
                } else{
                    printf("something went wrong :(");
                }
            } else{
                //printf("its not a number!");
            }
            
        }
    }

    printf("Closing program...");

    getchar(); //на всякий чтобы терминал не закрывался
    getchar();
}