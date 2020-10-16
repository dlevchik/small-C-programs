#include<stdio.h>
#define HI "Program helps you to reverse your array\n\nPlease insert array size:\n"     //строка что выводится при запуске программы

int size;       //переменная-величина массива

void printArr(int * , int);     //функция для вывода массива в консоль
void arrReverse(int *, int);        //функция для изменения порядка массива на противоположный


void main(void){

    printf("%s", HI);

    scanf("%d", &size);     //создание массива переменной длины что вводится пользователем
    int ch[size];

    for (int i = 0; i < size; i++)
    {
        printf("\n%d element of %d-sized array:\n", i + 1, size);       //запрос и запись значения определенного элемента массива
        scanf("%d", ch + i);
    }
    
    printf("\nyour array is:");
    printArr(ch, size);
    printf("\nReversing your array...");        //вывод входного массива, изменение порядка и вывод измененного массива
    arrReverse(ch, size);
    printf("\nNow your array is:");
    printArr(ch, size);

   getchar();       //чтобы программа не закрылась сразу
   getchar();
}

void printArr(int * arr, int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%3d", i);       //вывод номера ячейки в первой строке
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%3d", arr[i]);      //вывод значения ячейки во второй строке
    }
}

void arrReverse(int * arr, int size){
    int buffer;         //для хранения промежуточного значения
    for (int i = 0; i < (size / 2); i++)        //повторять с обоих концов до середины(половины от величины)
    {
        buffer = arr[i];        //запись промежуточного значения
        arr[i] = arr[(size-1)-i];       //первый элемент теперь последний
        arr[(size-1)-i] = buffer;       //последний элемент теперь первый(вот для чего промежуточное значение)
    }
}
