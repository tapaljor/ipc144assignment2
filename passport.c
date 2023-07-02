#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME_SIZE 50

void getFirstNameFromApplicant(char str[]); 
void getLastNameFromApplicant(char str[]); 
char *getStringFromUser(); 
int checkName(char *);
int getAgeFromApplicant();
int checkAge(int);
void clearInputBuffer(void);

int main(void) {

    char firstName[NAME_SIZE] = "";
    char lastName[NAME_SIZE] = "";

    getFirstNameFromApplicant(firstName);
    getLastNameFromApplicant(lastName);
    int age = getAgeFromApplicant();

    printf("Name: %s %s Age = %d\n", firstName, lastName, age);

    return 0;
}
void getFirstNameFromApplicant(char ar[]) {

    printf("Enter your first name: ");
    strcpy(ar, getStringFromUser());
}
void getLastNameFromApplicant(char ar[]) {

    printf("Enter your last name: ");
    strcpy(ar, getStringFromUser());
}
int checkName(char *str) {

    int checkCharacter = 0;
    int checkAlpha = 0;

    if (strlen(str) < 1) {
        printf("Name should be more than one character\n");
        checkCharacter++;
    }
    for (unsigned int a = 0; a < strlen(str); a++) {

        if (!isalpha(str[a]) || isspace(str[a])) { // checks for alphas only
            checkAlpha++;
        }
    }
    if (checkAlpha > 0) {
        printf("Name should be only a-z or A-Z\n");
    }
    if (checkCharacter > 0 || checkAlpha > 0) {
        return 0;
    } else {
        return 1;
    }
}
int getAgeFromApplicant() {

    int check = 0;
    int age = 0;
    printf("Enter age (16 or older): ");
    scanf("%d", &age);
    clearInputBuffer();

    check = checkAge(age);

    if (check == 0) {
        getAgeFromApplicant();
    } else {
        return age;
    }
}
int checkAge(int age) {

    if ( age >= 16) {
        return 1;
    } else {
        return 0;
    }
}
char *getStringFromUser() {

    int check = 0;
    static char str[NAME_SIZE]; // assuming max character length is 50

    scanf("%[^\n]", str);
    clearInputBuffer();

    check = checkName(str); // it checks the name string 

    if (check == 0) { // means false in name, let user enter name again

        printf("Please enter again: ");
        getStringFromUser();
    }
    return str;
}
void clearInputBuffer(void) {

    while (getchar() != '\n') {
        ; // On purpose: do nothing
    }
}