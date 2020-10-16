#include<stdio.h>
#define FORMULA ((((((arr[0][0] * arr[1][1] * arr[2][2]) + (arr[0][1] * arr[1][2] * arr[2][0])) + (arr[0][2] * arr[1][0] * arr[2][1])) - (arr[0][2] * arr[1][1] * arr[2][0])) - (arr[0][1] * arr[1][2] * arr[2][0])) - (arr[0][0] * arr[1][2] * arr[2][1]))
#define meh rhh + fff

// #define SIZE 3
// int ch[SIZE][SIZE] = {
//     {5,63,7},
//     {7,3,8},
//     {0,2,2}};

// #define SIZE 4
// int ch[SIZE][SIZE] = {
//     {5,63,7,3},
//     {7,3,8,3},
//     {0,2,2,8},
//     {9,3,9,3}};

int size;


void printArr(int * , int);
void printMatrix(int (*arr)[size]);
int det(const int (*arr)[size]);
int rhh = 5;
int fff = 4;


void main(void){
    // printf("insert array size\n");
    // scanf("%d", &size);
    // int ch[size];
    // for (int i = 0; i < size; i++)
    // {
    //     printf("\n%d element of %d-sized array:\n", i + 1, size);
    //     scanf("%d", ch + i);
    // }
    printf("%d\n", meh);

    printf("insert array size\n");
    scanf("%d", &size);
    int ch[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("\n%d element of %d row of %dx%d-sized array:\n", j+1, i+1, size, size);
            scanf("%d", (ch[i]) + j);
        }
        
    }
    
    
    printf("\nyour array is:");
    // printArr(ch, size);
    printMatrix(ch);
    printf("\nit\'s det is: %d", det(ch));
   getchar();
   getchar();
}

void printArr(int * arr, int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%3d", arr[i]);
    }
}

void printMatrix(int (*arr)[size]){
    printf("\n   ");
    for (int i = 0; i < size; i++)
    {
        printf("%3d", i);
    }
    for (int i = 0; i < size; i++)
    {
        printf("\n%3d", i);
        for (size_t j = 0; j < size; j++)
        {
            printf("%3d", *(*(arr+i)+j));
            // printf("%3d", arr[i][j]);
        }
        
    }
        
}

int det(const int (*arr)[size]){
    int detV = 0;
    switch (size)
    {
    case 1:
        detV = arr[0][0];
    break;

    case 2:
        detV = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    break;

    case 3:
        detV = FORMULA;
    break;

    default:
        printf("\nSowwy, we don\'t know how to process big matrix:(");
    }

    return detV;
}