#include<stdio.h>

int ch;
long int factorial(int num);

void main(void){
    printf("Insert value(s) that <20 to calculate factorial(or type Ctrl+Z to end program):"); //сообщение что выводится в начале программы
    while(scanf("%d", &ch) == 1){   //цикл для постоянной работы программы
        printf("\n%ld\n", factorial(ch));
    }
    
    getchar();
    getchar();
}

long int factorial(int num){    //сама функция
    long int total = 1;
    for (int i = num; i > 0; i--)  
    {
        //printf("|\'%d\'|", total);    //для тестов
        total *= i;        //факториал
    }
    return total;
}