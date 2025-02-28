#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

float average(int sum);

int main() {
    srand(time(NULL));

    int array[SIZE];
    int sum = 0;

    printf("Generated numbers: ");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
        sum += array[i];
    }

    printf("\nTotal sum: %d\n", sum);
    printf("Average value: %.2f", average(sum));

    return 0;
}

float average(int sum) {
    return (float) sum / SIZE;
}
