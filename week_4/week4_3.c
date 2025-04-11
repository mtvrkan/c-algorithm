#include <stdio.h>
#include <string.h>

char username[100];
char password[100];

char dbUsername[100] = "mehmet";
char dbPassword[100] = "12345";

void inputUsername(char array[]);

void inputPassword(char array[]);

void input(char array[], void (*inputFunc)(char array[]));

void control(char username[], char password[]);

int main() {
    input(username, inputUsername);
    input(password, inputPassword);

    control(username, password);

    return 0;
}

void inputUsername(char array[]) {
    printf("Please enter your username: ");
    scanf("%s", array);
}

void inputPassword(char array[]) {
    printf("Please enter your password: ");
    scanf("%s", array);
}

void input(char array[], void (*inputFunc)(char array[])) {
    inputFunc(array);
}

void control(char username[], char password[]) {
    if (strcmp(username, dbUsername) != 0) {
        printf("Username is not correct.\n");
        return;
    }

    if (strcmp(password, dbPassword) != 0) {
        printf("Password is not correct.\n");
        return;
    }

    printf("Welcome %s!", username);
}