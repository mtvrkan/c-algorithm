#include <stdio.h>

char username[100];
char password[100];

void inputUsername(char array[]);

void inputPassword(char array[]);

void input(char array[], void (*inputFunc)(char array[]));

int main() {
    input(username, inputUsername);
    input(password, inputPassword);

    printf("%s\n", username);
    printf("%s", password);

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
