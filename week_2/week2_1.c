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
    int maxCount = 0; // Modun en yüksek tekrar sayısını saklamak için değişken
    int mode = array[0]; // Mod olarak başlangıçta dizinin ilk elemanını varsayıyoruz

    for (int i = 0; i < SIZE; i++) {  // Dizinin her elemanı için döngü başlatıyoruz
        int count = 0; // Mevcut elemanın kaç kez geçtiğini saymak için değişken

        for (int j = 0; j < SIZE; j++) { // İç içe döngü ile dizinin her elemanını kontrol ediyoruz
            if (array[i] == array[j]) count++; // Aynı elemanı buldukça sayacı artırıyoruz
        }

        if (count > maxCount) { // Eğer bu eleman, şu ana kadarki en sık tekrar eden elemandan fazla tekrar ettiyse
            maxCount = count; // Yeni maksimum tekrar sayısını güncelliyoruz
            mode = array[i]; // Mod değerini güncelliyoruz
        }
    }

    // Bulunan modu ve kaç kez tekrar ettiğini ekrana yazdırıyoruz
    printf("Mode of the array is: %d (%d)\n", mode, maxCount);
}