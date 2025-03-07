#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int array[SIZE];

void randomValueGenerator(int array[]);

void printArray(int array[]);

void bubbleSort(int array[]);

void findMedian(int array[]);

void findMode(int array[]);

int main() {
    srand(time(NULL));

    randomValueGenerator(array);
    printArray(array);
    bubbleSort(array);
    findMedian(array);
    findMode(array);

    return 0;
}

void randomValueGenerator(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 11;
    }
}

void printArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    puts("");
}

void bubbleSort(int array[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                const int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printArray(array);
}

void findMedian(int array[]) {
    printf("Median of the array is: %d\n", array[SIZE / 2]);
}

void findMode(int array[]) {
    int maxCount = 0;
    int mode = array[0];

    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (array[i] == array[j]) count++;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = array[i];
        }
    }

    printf("Mode of the array is: %d (%d)\n", mode, maxCount);
}