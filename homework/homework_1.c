#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomMatrix(int rows, int cols, int matrix[rows][cols]);

void printMatrix(int rows, int cols, const int matrix[rows][cols]);

void sumMatrix(int rows, int cols, const int arr1[rows][cols], const int arr2[rows][cols]);

void multiMatrix(int rowsA, int colsA, const int arr1[rowsA][colsA], int rowsB, int colsB, const int arr2[rowsB][colsB]);

int main() {
    srand(time(NULL));

    int rowsA, colsA, rowsB, colsB;

    printf("Enter dimensions for Matrix A (Rows Cols): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter dimensions for Matrix B (Rows Cols): ");
    scanf("%d %d", &rowsB, &colsB);

    int matrixA[rowsA][colsA], matrixB[rowsB][colsB];

    generateRandomMatrix(rowsA, colsA, matrixA);
    generateRandomMatrix(rowsB, colsB, matrixB);

    printf("\n**** Matrix A ****\n");
    printMatrix(rowsA, colsA, matrixA);

    printf("\n**** Matrix B ****\n");
    printMatrix(rowsB, colsB, matrixB);

    printf("\n**** Sum of Matrix ****\n");
    if (rowsA == rowsB && colsA == colsB)
        sumMatrix(rowsA, colsA, matrixA, matrixB);
    else
        printf("Addition is undefined.\n");

    printf("\n**** Matrix Multiplication ****\n");
    if (colsA == rowsB)
        multiMatrix(rowsA, colsA, matrixA, rowsB, colsB, matrixB);
    else
        printf("Multiplication is undefined.\n");

    return 0;
}

void generateRandomMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void printMatrix(int rows, int cols, const int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

void sumMatrix(int rows, int cols, const int arr1[rows][cols], const int arr2[rows][cols]) {
    int result[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printMatrix(rows, cols, result);
}

void multiMatrix(int rowsA, int colsA, const int arr1[rowsA][colsA], int rowsB, int colsB, const int arr2[rowsB][colsB]) {
    int result[rowsA][colsB];

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printMatrix(rowsA, colsB, result);
}