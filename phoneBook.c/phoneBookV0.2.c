//TODO: fix filename

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAMES_SIZE 20
#define NUMBER_SIZE 13
#define TEMPARRAY_SIZE 3
#define MENU_PUNCTS 4
#define EDIT_PUNCTS 4
#define FILENAME "tel.txt"

typedef struct teleph {
	char name[NAMES_SIZE];
	char surname[NAMES_SIZE];
	char number[NUMBER_SIZE];
} TELSTRUCT;

TELSTRUCT * addElement(TELSTRUCT *telArr, TELSTRUCT *newContact, int * size);
void displayContacts(const TELSTRUCT * const telArr, const int size);
void sortArr(TELSTRUCT * const telArr, const int size);
TELSTRUCT * delElement(TELSTRUCT *telArr, const int id, int * size);
void saveFile(const TELSTRUCT * const telArr, const char * const filename, const int size);
TELSTRUCT * readFile(TELSTRUCT * telArr, const char * const filename, int * size);
char * getFunc(char * str, int n);  
int choose(int menuChoices);
void wait(void);
TELSTRUCT * addContact(TELSTRUCT *telArr, int * size);
int getData(char * str, int isNumber);
TELSTRUCT * editContact(TELSTRUCT *telArr, int * size);
void search(TELSTRUCT * const telArr, const int size);


int main(void) {

	TELSTRUCT *teleBookArr; 

	int size = 0;

    teleBookArr = readFile(teleBookArr, "tele", &size);
    while (1)
    {
        printf("PhoneBook.c. Your pesonal phone book that simply works!\2\n\n");

        sortArr(teleBookArr, size);
        displayContacts(teleBookArr, size);

        if(size == 0){
            printf("\nWant to add your first contact?");
            wait();

            teleBookArr = addContact(teleBookArr, &size);
            system("cls");
            displayContacts(teleBookArr, size);
        }

        printf("\n\nOperations with contacts:\n");
        printf("1) Add contact;\n");
        printf("2) Edit contact;\n");
        printf("3) Find contact;\n");
        printf("4) Save contacts into file;");
        printf("\nPlease choose operation or type '/q' to close the program:");

        switch (choose(MENU_PUNCTS))
        {

        case -1:
            saveFile(teleBookArr, "tele", size);
            free(teleBookArr);
            return 0;
        break;

        case 1:
            system("cls");
            teleBookArr = addContact(teleBookArr, &size);
            printf("last operation:addContact()\n");
        break;

        case 2:
            teleBookArr = editContact(teleBookArr, &size);
            system("cls");
            printf("last operation:editContact()\n");
        break;

        case 3:
            system("cls");
            search(teleBookArr, size);
            printf("last operation:search()\n");
        break;

        case 4:
            system("cls");

            saveFile(teleBookArr, "tele", size);
            printf("Contacts successfully saved!");

            wait();
            printf("last operation:saveFile()\n");
        break;
        
        default:
            printf("\n\aSomething gone wrong(");
            return -1;
        break;
        }
    }
    
    __mingw_free(teleBookArr);
	getchar();
    getchar();

	return 0;
}

TELSTRUCT* addElement(TELSTRUCT *telArr, TELSTRUCT *newContact, int * size){
    if (*size == 0)
    {
        telArr = (TELSTRUCT*) malloc(sizeof(TELSTRUCT));
        if (!telArr)
        {
            fprintf(stdout, "addElement() malloc() ERROR;");
            exit(EXIT_FAILURE);
        }
        
    }
        *size += 1;
        
        telArr = (TELSTRUCT*) __mingw_realloc(telArr, sizeof(TELSTRUCT) * (*size));
        if (!telArr)
        {
            fprintf(stdout, "realloc() addElement ERROR;");
            exit(EXIT_FAILURE);
        }
        
        telArr[*size - 1] = *newContact;
     
        return telArr;
}

void displayContacts(const TELSTRUCT * const telArr, const int size){

    if(size == 0){
        printf("Sorry, it seems that you have nobody to call :(\nGo and add some friends here!\2");
    } else
    {

        printf("Here\'s all of your %d contacts:\n\n", size);

        printf("   %*s|%*s|%*s\n", NAMES_SIZE, "Name", NAMES_SIZE, "Father name", NUMBER_SIZE, "Number");
        
        for (int i = 0; i < NAMES_SIZE * 2 + NUMBER_SIZE + 5; i++)
        {
            printf("=");
        }

        for (int i = 0; i < size; i++)
        { 
            printf("\n%2d.%*s|%*s|%*s", i + 1, NAMES_SIZE, (telArr+i)->name, NAMES_SIZE, (telArr+i)->surname, NUMBER_SIZE, (telArr+i)->number);
        }
    }
}


//TODO: sort piinters not structs itself
void sortArr(TELSTRUCT * telArr, const int size){
    TELSTRUCT temp;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strncmp((telArr+i)->name, (telArr+j)->name, strlen((telArr+j)->name)) > 0)
            {
                temp = *(telArr+i);
                *(telArr+i) = *(telArr+j);
                *(telArr+j) = temp;
            }  
        }
    }
}

TELSTRUCT * delElement(TELSTRUCT *telArr, const int id, int * size){

    for (int i = id - 1; i < *size; i++){
        *(telArr+i) = *(telArr+i+1);
    }
    
    __mingw_free(telArr+(*size)-1);
    
    *size -= 1;
    
    telArr = (TELSTRUCT*) __mingw_realloc(telArr, sizeof(TELSTRUCT) * (*size));

    if (!telArr){
        fprintf(stdout, "realloc() delElement() ERROR;");
        exit(EXIT_FAILURE);
    }

    return telArr;
}

//TODO: fix file name;
void saveFile(const TELSTRUCT * const telArr, const char * const filename, const int size){
    FILE * fileP;

    char * filetxt = (char*) malloc(sizeof(char) * (strlen(filename)+5));

    if(!filetxt){
        fprintf(stdout, "saveFile() malloc() ERROR;");
        exit(EXIT_FAILURE);
    }

    strncpy(filetxt, filename, strlen(filename)-1);
    //printf("|%s|", filetxt);
    strncat(filetxt, ".txt", 5);
    //printf("|%s|", filetxt);

    if((fileP = fopen(FILENAME, "w")) == NULL){
        fprintf(stdout, "Can't create %s\n", filetxt);
        exit(EXIT_FAILURE);
    }

    //fprintf(fileP, "This text was auto-generated by PhoneBook.c, changing it might lead to errors in program.\n\n");
    //fprintf(fileP, "You have %d contacts in your phone book:", size);
    fprintf(fileP, "%d", size);
 
    for (int i = 0; i < size; i++){ 
        fprintf(fileP, "\n%*s%*s%*s", NAMES_SIZE, (telArr+i)->name, NAMES_SIZE, (telArr+i)->surname, NUMBER_SIZE, (telArr+i)->number);
    }

    if (fclose(fileP) != 0){
        fprintf(stderr, "Can't close the file");
        exit(EXIT_FAILURE);
    }

    free(filetxt);
}

//TODO: fix file name;
TELSTRUCT * readFile(TELSTRUCT * telArr, const char * const filename, int * size){
    FILE * fileP;
    int sz;

    TELSTRUCT tempStruct;

    char * filetxt = (char*) malloc(sizeof(char) * (strlen(filename)+5));

    if(!filetxt){
        fprintf(stdout, "readFile() malloc() ERROR;");
        exit(EXIT_FAILURE);
    }

    strncpy(filetxt, filename, strlen(filename));
    //printf("|%s|", filetxt);
    strncat(filetxt, ".txt", 5);
    //printf("|%s|", filetxt);

    if((fileP = fopen(FILENAME, "r")) == NULL){
        //fprintf(stdout, "Can't read %s\n", filetxt);
        //exit(EXIT_FAILURE);
        return telArr;
    }

    fscanf(fileP, "%d", &sz);

    if(sz == 0){
        return telArr;
    }

    for (int i = 0; i < sz; i++)
    {
        fscanf(fileP, "%s%s%s", tempStruct.name, tempStruct.surname, tempStruct.number);
        telArr = addElement(telArr, &tempStruct, size);
    }

    if (fclose(fileP) != 0){
        fprintf(stderr, "Can't close the file");
        exit(EXIT_FAILURE);
    }
    
    return telArr;
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

void wait(void){
    printf("\n\nPress any key to continue...");

    char gh[6];
    getFunc(gh, 6);
    system("cls");
}

TELSTRUCT * addContact(TELSTRUCT *telArr, int * size){
    system("cls");

    TELSTRUCT tempStruct;

    printf("Creating a new contact...\nFirstly insert contact's name(>%d symbols) or type '/q' to cancel:", NAMES_SIZE);

    if (getData(tempStruct.name, 0) == -1)
    {
        return telArr;
    }
    
    system("cls");
    printf("Now insert contact's surname(>%d symbols) or type '/q' to cancel:", NAMES_SIZE);

    if (getData(tempStruct.surname, 0) == -1)
    {
        return telArr;
    }

    system("cls");
    printf("It\'s now time to insert contact number(>%d numbers) or type '/q' to cancel:", NUMBER_SIZE);

    if (getData(tempStruct.number, 1) == -1)
    {
        return telArr;
    }

    telArr = addElement(telArr, &tempStruct, size);

    system("cls");
    printf("Contact \'%s\' successfully created!\n", tempStruct.name);

    wait();

    return telArr;
}

int getData(char * str, int isNumber){

    int flag = 0;
    int isD;

    do {

        isD = 0;

        if (!str[0] && flag > 0){
            printf("\nIncorrect input, please try again\n");
        }

        ++flag;

        for(int i = 0; i < NUMBER_SIZE; i++){
            str[i] = '\0';
        }

        if(isNumber){
            getFunc(str, NUMBER_SIZE);}else{
            getFunc(str, NAMES_SIZE);
        }
        

        if(strncmp(str, "/q", 3) == 0){
            system("cls");
            return -1;
        }

        if(isNumber){
            for (int i = 0; i < NUMBER_SIZE; i++){
                if (!isdigit(str[i]) && str[i] != '\0'){
                    printf("\nNumber must contain only digits!");
                    isD = 1;
                    break;
                }
            } 
        }
    } while (isD == 1 || str[0] == '\0');

    return 1;
}

TELSTRUCT * editContact(TELSTRUCT *telArr, int * size){
    printf("\n\nPlease write ID of the contact you want to edit(1-%d) or \'/q\' to cancel:", *size);

    int slot = choose(*size);
    if(slot == -1){
        system("cls");
        return telArr;
    }
    --slot;

    char oldData[NAMES_SIZE] = "\0";

    printf("Now choose operation:\n1)Edit name;\n2)Edit surname;\n3)Edit number;\n4)Delete contact\n\'/q\' to cancel\n");

    switch (choose(EDIT_PUNCTS))
    {
    case -1:
       return telArr;
    break;

    case 1:
        system("cls");
        printf("Editing \'%s\' name.\nInsert new name(>%d symbols) or type '/q' to cancel:", (telArr+slot)->name, NAMES_SIZE);

        strncpy(oldData, (telArr+slot)->name, NAMES_SIZE);

        if (getData((telArr+slot)->name, 0) == -1){
            strncpy((telArr+slot)->name, oldData, NAMES_SIZE);
            return telArr;
        }

        printf("Successfully edited!");
        wait();
    break;

    case 2:
        system("cls");
        printf("Editing \'%s\' surname.\nInsert new surname(>%d symbols) or type '/q' to cancel:", (telArr+slot)->surname, NAMES_SIZE);

        strncpy(oldData, (telArr+slot)->surname, NAMES_SIZE);

        if (getData((telArr+slot)->surname, 0) == -1){
            strncpy((telArr+slot)->surname, oldData, NAMES_SIZE);
            return telArr;
        }

        printf("Successfully edited!");
        wait();
    break;

    case 3:
        system("cls");
        printf("Editing \'%s\' number.\nInsert new number(>%d symbols) or type '/q' to cancel:", (telArr+slot)->number, NUMBER_SIZE);

        strncpy(oldData, (telArr+slot)->number, NUMBER_SIZE);

        if (getData((telArr+slot)->number, 1) == -1){
            strncpy((telArr+slot)->number, oldData, NUMBER_SIZE);
            return telArr;
        }

        printf("Successfully edited!");
        wait();
    break;

    case 4:
        system("cls");
        printf("Are you sure you want to delete %s? 1)yes; 2) no;", (telArr+slot)->name);

        if(choose(2) == 2){
            return telArr;
        }

        printf("%s successfully deleted!", (telArr+slot)->name);
        telArr = delElement(telArr, slot+1, size);
        wait();
    break;
    
    default:
        printf("\n\aSomething gone wrong(");
        return telArr;
    break;
    }

    return telArr;
}

void search(TELSTRUCT * const telArr, const int size){
    printf("\nPlease insert search querry or type \'/q\' to cancel:");

    char searchQuerry[NAMES_SIZE] = "1";

    if(getData(searchQuerry, 0) == -1){
        return;
    }

    system("cls");
    printf("Found results:\n");

    for (int i = 0, j = 0; i < size; i++)
        {
            if (strncmp((telArr+i)->name, searchQuerry, strlen(searchQuerry)) == 0 || strncmp((telArr+i)->surname, searchQuerry, strlen(searchQuerry)) == 0 || strncmp((telArr+i)->number, searchQuerry, strlen(searchQuerry)) == 0)
            {
                printf("%*s|%*s|%*s", NAMES_SIZE, (telArr+i)->name, NAMES_SIZE, (telArr+i)->surname, NUMBER_SIZE, (telArr+i)->number);
                ++j;
            }
            if(i == size - 1 && j == 0){
                printf("\nNo results found matching your request\n");
            }
        }
    
    wait();
}