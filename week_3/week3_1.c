#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 2
#define COLS 2

int array1[ROWS][COLS];
int array2[ROWS][COLS];
int targetMatrix[ROWS][COLS];

void randomValueGenerator(int matrix[ROWS][COLS]);

void printMatrix(int matrix[ROWS][COLS]);

void sumMatrix(int arr1[ROWS][COLS], int arr2[ROWS][COLS]);

void multiMatrix(int arr1[ROWS][COLS], int arr2[ROWS][COLS]);

void transposeMatrix(int matrix[ROWS][COLS]);

int main() {
    srand(time(NULL));

    randomValueGenerator(array1);
    randomValueGenerator(array2);

    printf("**** 1. Matrix ****\n");
    printMatrix(array1);

    printf("**** 2. Matrix ****\n");
    printMatrix(array2);

    printf("**** Sum Matrix ****\n");
    sumMatrix(array1, array2);

    printf("**** Multi Matrix ****\n");
    multiMatrix(array1, array2);

    printf("**** Matrix Transpose ****\n");
    transposeMatrix(targetMatrix);

    return 0;
}

void randomValueGenerator(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }

        puts("");
    }
}

void sumMatrix(int arr1[ROWS][COLS], int arr2[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            targetMatrix[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printMatrix(targetMatrix);
}

void multiMatrix(int arr1[ROWS][COLS], int arr2[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            targetMatrix[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                targetMatrix[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printMatrix(targetMatrix);
}

void transposeMatrix(int matrix[ROWS][COLS]) {
    int temp[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp[i][j] = matrix[j][i];
        }
    }

    printMatrix(temp);
}