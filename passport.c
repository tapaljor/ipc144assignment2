/*
IPC144 N1F - Assignment 2
Group #2
Sheba Birhanu
Masoumeh Hosseinnazhad
Tashi Paljor

C CODE
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME_SIZE 50

void getFirstNameFromApplicant(char *);
void getLastNameFromApplicant(char *);
char *getStringFromUser();
int checkName(char *);
int getAgeFromApplicant();
int checkAge(int);
void clearInputBuffer(void); //clearing the input buffer espcially for Windows computer

int main(void) {

        int sentiVal = 0;
        size_t token = 0;
      
        while(sentiVal != -1 && token < 2000) { //if token is less than 2k and user didn't exit the loop

            char firstName[NAME_SIZE] = "";
            char lastName[NAME_SIZE] = "";

            getFirstNameFromApplicant(firstName);
            getLastNameFromApplicant(lastName);
            int age = getAgeFromApplicant();

            printf("Name: %s %s Age = %d\n", firstName, lastName, age);
            token++;

            printf("Application successful. \nEnter any key to continue and -1 to exit.\n");
            scanf("%d", &sentiVal);
            clearInputBuffer();
        }
        if ( token > 2000) {
            printf("Application Limit reached for today, please try again tomorrow.");
        }
        return 1;
}
void getFirstNameFromApplicant(char *ar) {

        printf("Enter your first name: ");
        strcpy(ar, getStringFromUser());
}
void getLastNameFromApplicant(char *ar) {

        printf("Enter your last name: ");
        strcpy(ar, getStringFromUser());
}
int checkName(char *str) {

        int checkCharacter = 0;
        int checkAlpha = 0;

        if (strlen(str) < 2) {
            printf("Name should be more than one character\n");
            checkCharacter++;
        }
        for (size_t a = 0; a < strlen(str); a++) {

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
        printf("Enter age (older than 16): ");
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

        if ( age > 16) {
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

        check = checkName(str); // it checks the name string, expects 1 if conditions met, else 0

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
