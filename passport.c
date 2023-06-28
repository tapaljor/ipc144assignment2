#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME_SIZE 50

void getFirstNameFromApplicant(char str[]);
void getLastNameFromApplicant(char str[]);
char* getStringFromUser();
int checkName(char *);
int getAgeFromApplicant();
int checkAge(int);
void clearInputBuffer(void);

//Something is added

int main(void) {

    char firstName[NAME_SIZE] = "";
    char lastName[NAME_SIZE] = "";

    getFirstNameFromApplicant(firstName);
    getLastNameFromApplicant(lastName);
    int age = getAgeFromApplicant();

    printf("Name: %s %s Age = %d\n", firstName, lastName, age);

    return 0;
}
char* getStringFromUser() {

    int check = 0;
    static char str[NAME_SIZE];//assuming max character length is 50

    scanf("%[^\n]", str);
    clearInputBuffer();

    check = checkName(str);//it checks the name character

    if ( check == 0) { // means false in name, let user enter name again
        printf("Please enter again: ");
        getStringFromUser(); 
    } 
    return str;
}
void getFirstNameFromApplicant(char ar[]) {

    printf("Enter your first name: ");
    char* str = getStringFromUser();
    strcpy(ar, str);
}
void getLastNameFromApplicant(char ar[]) {

    printf("Enter your last name: ");
    char* str = getStringFromUser();
    strcpy(ar, str);
}
int checkName(char* str) {

    //Declaration of variable reset to zero everytime called. 
    //These two integers are to detect any anything other than alpha or length is less than 1
    int checkCharacter = 0;
    int checkAlpha = 0;

    if ( strlen(str) < 1) {
        printf("Name should be more than one character\n");
        checkCharacter++;
    }
    for(unsigned int a = 0; a < strlen(str); a++) {
        if ( !isalpha(str[a]) || isspace(str[a])) { //checks for alphas only
           checkAlpha++; 
        }
    }
    if ( checkAlpha > 0) {
        printf("Name should be only a-z or A-Z\n");
    }
    if ( checkCharacter > 0 || checkAlpha > 0) {
        return 0;
    } else {
        return 1;
    }
}
int getAgeFromApplicant() {

    int check = 0;
    int age = 0;
    printf("Enter age (number only): ");
    scanf("%d", &age);

    check = checkAge(age);

    if (check == 0) {
        getAgeFromApplicant();
    } else {
        return age;
    } 
}
int checkAge(int age) {

    int check = 0;

    if ( isalpha(age)) {  //if input is not digit
        printf("Enter only number\n");
        check++;
    }
    else if (age < 16) {
        printf("Age should be 16 or older\n");
        check++;
    }

    if ( check > 0) { //age error
        return 0;
    } else {
        return 1;
    }
}
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard characters until newline or EOF is encountered
    }
}