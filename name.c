//программа просит ваше имя и фамилию а потом выводит их в виде таблицы с количеством букв в имени в ее нижнем ряде
#include <stdio.h>
#include <string.h>//библтотека для работы с строками

#define HI "PLS, insert your name, surname and age:\n"

char name[40];
char surname[40];
int age;

void main(void){

    printf("%s", HI);

    scanf("%s %s %d", name, surname, &age);

    printf("\a%s %s", name, surname);
    printf("\n%-*zd", strlen(name), strlen(name));
    printf(" %-*zd", strlen(surname), strlen(surname));

    getchar();
    getchar();
}