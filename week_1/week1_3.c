#include <stdio.h>

#define SIZE 5

int input();

int max(int array[]);

int min(int array[]);

int main() {
    int array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        printf("Enter the %d. number: ", i + 1);
        array[i] = input();
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d. array element = %d\n", i + 1, array[i]);
    }

    printf("The largest number is: %d\n", max(array));
    printf("The smallest number is: %d", min(array));

    return 0;
}

int input() {
    int number;
    scanf("%d", &number);
    return number;
}

int max(int array[]) {
    int max = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}

int min(int array[]) {
    int min = array[0];
    for (int i = 1; i < SIZE; i++) {
        if (min > array[i]) min = array[i];
    }
    return min;
}
