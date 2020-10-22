//this is unfinisfed program. Please check phoneBookV0.2.c

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRUCT_SIZE 100
#define MENU_PUNCTS 6
#define EDIT_PUNCTS 5
#define NAMES_SIZE 20
#define NUMBER_SIZE 13
#define TEMPARRAY_SIZE 3

struct teleph {
char name[NAMES_SIZE];
char surname[NAMES_SIZE];
char fathName[NAMES_SIZE];
char number[NAMES_SIZE];
} teleBookArr [STRUCT_SIZE];

int menu(void);
int choose(int menuChoices);
int wait(void);
int addContact(void);
char * getFunc(char * str, int n);  
int getdata(char * arr, int slot);
int display(void);
int editContact(void);
int search(void);
int sortArr(void);
int sort(int free);
int filef(void);

int main(void){
    int ch;

    for(int i = 0; i < STRUCT_SIZE; i++){
        teleBookArr[i].name[0] = '\0';
    }

    while(1){
        ch = menu();
        switch (ch)
        {

        case -1:
            return 0;
        break;

        case 1:
            system("cls");
            display();

            wait();

            printf("last operation:display()\n");
        break;

        case 2:
            system("cls");
            addContact();
            printf("last operation:addContact()\n");
        break;
        
        case 3:
            system("cls");
            editContact();
            printf("last operation:editContact()\n");
        break;

        case 4:
            system("cls");
            search();
            printf("last operation:search()\n");
        break;

        case 5:
            system("cls");
            sortArr();
            printf("last operation:sortArr()\n");
        break;

        case 6:
            system("cls");
            filef();
            printf("last operation:filef()\n");
        break;

        default:
            system("cls");
            printf("\n\aSomething gone wrong(");
        }
    }

    getchar();
    getchar();

    return 0;
}

int menu(void){

    printf("PhoneBook.c. Your pesonal phome book that simply works!\2\n\n");
    printf("Main menu:\n");
    printf("1) Display all my contacts;\n");
    printf("2) Add contact;\n");
    printf("3) Edit contact;\n");
    printf("4) Find contact;\n");
    printf("5) %cSort contacts;\n", 16);
    printf("6) %cFile operations;\n", 16);
    printf("\nPlease choose operation or type '/q' to close the program:");

    return choose(MENU_PUNCTS);
}

int choose(int menuChoices){
    int c = 1;
    char input[TEMPARRAY_SIZE];
    do {
        if (c <= 0 || c > menuChoices){
            printf("\nIncorrect input, please try again\n");
        }

        getFunc(input, TEMPARRAY_SIZE);

        if(strncmp(input, "/q", 2) == 0){
            return -1;
        }

        c = atoi(input);
    } while (c <= 0 || c > menuChoices);

    return c;
}

int wait(void){
    printf("\n\nPress any key to go back to continue...");

    char gh[6];
    getFunc(gh, 6);
    system("cls");
}

char * getFunc(char * str, int n){
    char * result;
    int i = 0;

    result = fgets(str, n, stdin);

    if(result){
        while (str[i] != '\n' && str[i] != '\0')
        {
            i++;
        }

        if(str[i] == '\n'){
            str[i] = '\0';
        } else{
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return result;
}

int addContact(void){
    int slot = -1;
    int input;
    
    for (int i = 0; i <= STRUCT_SIZE; i++)
    {
        if(teleBookArr[i].name[0] == '\0'){
            slot = i;
            //printf("%d",i);
            break;
        }
    }

    if(slot == -1 && slot != 0){
        printf("Sorry, it seems that you have run out of array memory so we can't create new contact :(");
        wait();
        return -1;
    }
    
    printf("Adding a new contact...\nFirstly insert contact's name(>%d symbols) or type '/q' to cancel:", NAMES_SIZE);
    if(getdata(teleBookArr[slot].name, slot) == -1){
        return -1;
    }

    system("cls");
    printf("Now insert contact's surname(>%d symbols) or type '/q' to cancel:", NAMES_SIZE);

    if(getdata(teleBookArr[slot].surname, slot) == -1){
        return -1;
    }
    
    system("cls");
    printf("Contact's fathers name(>%d symbols) or type '/q' to cancel:", NAMES_SIZE);

    if(getdata(teleBookArr[slot].fathName, slot) == -1){
        return -1;
    }

    system("cls");
    printf("It\'s now time to insert contact number(>%d numbers) or type '/q' to cancel:", NUMBER_SIZE);

    int isD;
    do{
        isD = 0;

        if(getdata(teleBookArr[slot].number, slot) == -1){
            return 0;
        }

        for (int i = 0; i < NUMBER_SIZE; i++){
            if (!isdigit(teleBookArr[slot].number[i]) && teleBookArr[slot].number[i] != '\0'){
                printf("\nNumber must contain only digits! Try again:");
                isD = 1;
                break;
            }
        }
        
    }while(isD == 1);

    system("cls");
    printf("Contact \'%s\' successfully created!\n", teleBookArr[slot].name);

    wait();

    return 0;
}

int getdata(char * arr, int slot){
    int i = 0;
    do {
        if (!arr[0] && i > 0){
            printf("\nIncorrect input, please try again\n");
        }
       
        ++i;
        getFunc(arr, NAMES_SIZE);

        if(strncmp(arr, "/q", 3) == 0){
            teleBookArr[slot].name[0] = '\0';
            system("cls");
            return -1;
        }
    } while (!arr[0]);
    return 1;
}

int display(void){
    if (teleBookArr[0].name[0] == '\0')
    {
        char gh[6];

        printf("Sorry, it seems that you have nobody to call :(\nGo and add some friends here!\2");
        return -1;
    }

    int free = 0;
    for (int i = 0; i < STRUCT_SIZE; i++)
    {
        if (teleBookArr[i].name[0] == '\0')
        {
            break;
        }
        ++free;
    }
    
    printf("Here\'s all of your %d contacts:\n\n", free);
    printf("   %*s|%*s|%*s|%*s", NAMES_SIZE, "Name", NAMES_SIZE, "Surname", NAMES_SIZE, "Father name", NUMBER_SIZE, "Number");

    for (int i = 0; i < free; i++)
    {
        printf("\n%2d.%*s|%*s|%*s|%*s", i + 1, NAMES_SIZE, teleBookArr[i].name, NAMES_SIZE, teleBookArr[i].surname, NAMES_SIZE, teleBookArr[i].fathName, NUMBER_SIZE, teleBookArr[i].number);
    }

    return free;
}

int editContact(void){

    system("cls");

    int free = display();

    if(free == -1){
        wait();
        return -1;
    }

    printf("\n\nPlease write number of the contact you want to edit(1-%d) or \'/q\' to cancel:", free);

    int slot = choose(free);
    if(slot == -1){
        system("cls");
        return -1;
    }
    --slot;

    printf("Now choose operation:\n1)Edit name;\n2)Edit surname;\n3)Edit father's name;\n4)Edit number;\n5)Delete contact\n\'/q\' to cancel\n");

    char oldData[NAMES_SIZE];

    switch (choose(EDIT_PUNCTS))
    {
    case -1:
        system("cls");
        return -1;
    break;

    case 1:
        system("cls");
        printf("name: %s\n", teleBookArr[slot].name);
        strncpy(oldData, teleBookArr[slot].name, NAMES_SIZE);
        printf("slot: %d\n", slot);
        printf("oldData: %s\n", oldData);
        printf("Editing \'%s\' name.\nInsert new name(>%d symbols) or type '/q' to cancel:", teleBookArr[slot].name, NAMES_SIZE);

        if(getdata(teleBookArr[slot].name, slot) == -1){
            strncpy(teleBookArr[slot].name, oldData, NAMES_SIZE);
            return -1;
        }
    break;

    case 2:
        system("cls");
        strncpy(oldData, teleBookArr[slot].surname, NAMES_SIZE);
        printf("Editing \'%s\' surname. \nInsert new surname(>%d symbols) or type '/q' to cancel:", teleBookArr[slot].surname, NAMES_SIZE);

        if(getdata(teleBookArr[slot].surname, slot) == -1){
            strncpy(teleBookArr[slot].surname, oldData, NAMES_SIZE);
            return -1;
        }
    break;

    case 3:
        system("cls");
        strncpy(oldData, teleBookArr[slot].fathName, NAMES_SIZE);
        printf("Editing \'%s\' father name. \nInsert new father name(>%d symbols) or type '/q' to cancel:", teleBookArr[slot].fathName, NAMES_SIZE);

        if(getdata(teleBookArr[slot].fathName, slot) == -1){
            strncpy(teleBookArr[slot].fathName, oldData, NAMES_SIZE);
            return -1;
        }
    break;

    case 4:
        system("cls");
        strncpy(oldData, teleBookArr[slot].number, NUMBER_SIZE);
        printf("Editing \'%s\' number. \nInsert new number(>%d symbols) or type '/q' to cancel:", teleBookArr[slot].number, NUMBER_SIZE);

        if(getdata(teleBookArr[slot].number, slot) == -1){
            strncpy(teleBookArr[slot].number, oldData, NUMBER_SIZE);
            return -1;
        }
    break;
    
    case 5:
        system("cls");
        printf("%s successfully deleted!", teleBookArr[slot].name);
        wait();
        //del(slot)
        //return -1;
    break;

    default:
        printf("\n\aSomething gone wrong(");
        return -1;
    break;
    }

    editContact();

    return 0;
}

int search(void){

    system("cls");

    int free = display();

    if(free == -1){
        wait();
        return -1;
    }

    char searchQuerry[NAMES_SIZE] = "1";

    printf("\nSearch through...\n1)Name;\n2)Number;\n\'/q\' - cancel;\n");
    switch (choose(2))
    {
    case -1:
        system("cls");
        return -1;
    break;

    case 1:
        printf("\nPlease insert search querry or type \'/q\' to cancel:");
        
        do {
            if (searchQuerry[0] == '\n'){
                printf("\nIncorrect input, please try again\n");
            }

            getFunc(searchQuerry, NAMES_SIZE);

            if(strncmp(searchQuerry, "/q", 2) == 0){
                system("cls");
                return -1;
            }
        }while (searchQuerry == 0);

        system("cls");
        printf("Found results:\n");

        for (int i = 0, j = 0; i < STRUCT_SIZE; i++)
        {
            if (teleBookArr[i].name[0] != '\0' && strncmp(teleBookArr[i].name, searchQuerry, strlen(searchQuerry)) == 0 || strncmp(teleBookArr[i].surname, searchQuerry, strlen(searchQuerry)) == 0 || strncmp(teleBookArr[i].name, searchQuerry, strlen(searchQuerry)) == 0)
            {
                printf("%*s|%*s|%*s|%*s", NAMES_SIZE, teleBookArr[i].name, NAMES_SIZE, teleBookArr[i].surname, NAMES_SIZE, teleBookArr[i].fathName, NUMBER_SIZE, teleBookArr[i].number);
                ++j;
            }
            if(i == STRUCT_SIZE - 1 && j == 0){
                printf("\nNo results found matching your request\n");
            }
        }

        wait();
        system("cls");     
    break;

    case 2:
        printf("\nPlease insert search querry or type \'/q\' to cancel:");

        int isD;
        do {
            isD = 0;

            if (searchQuerry[0] == '\n'){
                printf("\nIncorrect input, please try again\n");
            }

            getFunc(searchQuerry, NAMES_SIZE);

            if(strncmp(searchQuerry, "/q", 2) == 0){
                system("cls");
                return -1;
            }

            for (int i = 0; i < strlen(searchQuerry); i++){
                if (!isdigit(searchQuerry[i]) && searchQuerry[i] != '\0'){
                    printf("\nNumber must contain only digits! Try again:");
                    isD = 1;
                    break;
                }
            }
        }while (searchQuerry == 0 || isD == 1);

        system("cls");
        printf("Found results:\n");

        for (int i = 0, j = 0; i < STRUCT_SIZE; i++)
        {
            if (teleBookArr[i].name[0] != '\0' && strncmp(teleBookArr[i].number, searchQuerry, strlen(searchQuerry)) == 0)
            {
                printf("\n%*s|%*s|%*s|%*s", NAMES_SIZE, teleBookArr[i].name, NAMES_SIZE, teleBookArr[i].surname, NAMES_SIZE, teleBookArr[i].fathName, NUMBER_SIZE, teleBookArr[i].number);
                ++j;
            }
            if(i == STRUCT_SIZE - 1 && j == 0){
                printf("\nNo results found matching your request\n");
            }
        }

        wait();
        system("cls");
    break;
    
    default:
        printf("\n\aSomething gone wrong(");
        return -1;
    break;
    }
}

int sortArr(void){
    system("cls");

    int free = display();

    if(free == -1){
        wait();
        return -1;
    }

    printf("\nSort through...\n1)Name;\n2)Surname;\n3)Number;\n\'/q\' - cancel;\n");

    switch (choose(3))
    {
    case -1:
        system("cls");
        return -1;
    break;

    case 1:
    case 2:
    case 3:
        printf("\aWork in progress:(\n");
        wait();
        return 0;
        //sort(free);
        // char * temp = NULL;
        // int i, j;
        // for (i = 0; i < free-1; i++)
        // {
        //     for (j = i + 1; j < free; j++)
        //     {
        //         if (strncmp(tolower(teleBookArr[i].name), tolower(teleBookArr[j].name), strlen(teleBookArr[j].name)))
        //         {
        //             temp = * teleBookArr[i].name;
        //             * teleBookArr[i].name = * teleBookArr[j].name;
        //             * teleBookArr[j].name = temp;
        //         }  
        //     }
        // }
    
    break;
    
    default:
        printf("\n\aSomething gone wrong(");
        return -1;
    break;
    }

    return 0;
}

// int sort(int free){
//     char * temp;
//     int i, j;
//     for (i = 0; i < free-1; i++)
//     {
//         for (j = i + 1; j < free; j++)
//         {
//             if (strncmp(tolower(teleBookArr[i].name), tolower(teleBookArr[j].name), strlen(teleBookArr[j].name)))
//             {
//                 temp = * teleBookArr[i].name;
//                 * teleBookArr[i].name = * teleBookArr[j].name;
//                 * teleBookArr[j].name = temp;
//             }  
//         }
//     }
    
// }

int filef(void){
    system("cls");

    int free = display();

    if(free == -1){
        printf("\n\nWant to read contacts from file?\n1)Yes;\n2)No, thanks\n");
                    
        if(choose(2) == 1){
            printf("\nReading from file...");
        }else{
            system("cls");
            return 0;
        }
        
        wait();
        return -1;
    }

    printf("\n\nSelect file operation:\n1)Write contacts in file;\n2)Read contacts from file;\n'/q\' - cancel;\n");

    char filename[NAMES_SIZE];
    int i;
    FILE * filePoint;

    switch (choose(2))
    {

    case -1:
        system("cls");
        return -1;
    break;

    case 1:
        i = 0;
        system("cls");
        printf("Please insert file name or type \'/q\' to cancel:");

        do {
            if (!filename[0] && i > 0){
                printf("\nIncorrect input, please try again\n");
            }
        
            ++i;
            getFunc(filename, NAMES_SIZE);

            if(strncmp(filename, "/q", 3) == 0){
                system("cls");
                return -1;
            }
        } while (!filename);

        strncat(filename, ".txt", 5);

        if((filePoint = fopen(filename, "w")) == NULL){
            fprintf(stdout, "Can't create %s\n", filename);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < free; i++)
        {
            fprintf(filePoint, "%s %s %s %s\n", teleBookArr[i].name, teleBookArr[i].surname, teleBookArr[i].fathName, teleBookArr[i].number);
        }
        
        printf("Done! %s successfully created in this directory.", filename);

        if (fclose(filePoint) != 0)
        {
            fprintf(stderr, "Can't close the file");
            exit(EXIT_FAILURE);
        }

        wait();
        system("cls");
    break;

    case 2:
        i = 0;
        system("cls");
        printf("Please insert file name or type \'/q\' to cancel:");

        do {
            if (!filename[0] && i > 0){
                printf("\nIncorrect input, please try again\n");
            }
        
            ++i;
            getFunc(filename, NAMES_SIZE);

            if(strncmp(filename, "/q", 3) == 0){
                system("cls");
                return -1;
            }
        } while (!filename);

        strncat(filename, ".txt", 5);

        if((filePoint = fopen(filename, "r")) == NULL){
            fprintf(stdout, "Can't read %s\n", filename);
            exit(EXIT_FAILURE);
        }

        int j = 0;

        while (fscanf(filePoint, "%s %s %s %s\n", teleBookArr[j].name, teleBookArr[j].surname, teleBookArr[j].fathName, teleBookArr[j].number) == 4)
        {
            j++;
        }

        printf("\nSuccessfully found %d contacts!", j + 1);

        if (fclose(filePoint) != 0)
        {
            fprintf(stderr, "Can't close the file");
            exit(EXIT_FAILURE);
        }

        wait();
        system("cls");
    break;
    
    default:
        printf("\n\aSomething gone wrong(");
        return -1;
    break;
}
}