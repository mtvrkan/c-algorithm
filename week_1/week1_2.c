#include <stdio.h>

#define SIZE 5

int input();

int main() {
    int array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        printf("Enter the %d. number: ", i + 1);
        array[i] = input();
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d. array element = %d\n", i + 1, array[i]);
    }

    return 0;
}

int input() {
    int number;
    scanf("%d", &number);
    return number;
}
