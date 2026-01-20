#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50000

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    long long comparisons = 0, assignments = 0;
    clock_t start = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                assignments += 3;
            }
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("Bubble Sort: Tempo = %f ms, Comparacoes = %lld, Atribuicoes = %lld\n", time_taken, comparisons, assignments);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    long long comparisons = 0, assignments = 0;
    clock_t start = clock();
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            assignments += 3;
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("Selection Sort: Tempo = %f ms, Comparacoes = %lld, Atribuicoes = %lld\n", time_taken, comparisons, assignments);
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    long long comparisons = 0, assignments = 0;
    clock_t start = clock();
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            assignments++;
        }
        arr[j + 1] = key;
        assignments++;
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("Insertion Sort: Tempo = %f ms, Comparacoes = %lld, Atribuicoes = %lld\n", time_taken, comparisons, assignments);
}

int main() {
    srand(time(NULL));
    int arr[SIZE];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[j] = rand() % 1000; // generate random numbers between 0 and 999
        }
        bubbleSort(arr, SIZE);
        for (int j = 0; j < SIZE; j++) {
            arr[j] = rand() % 1000; // generate new random numbers
        }
        selectionSort(arr, SIZE);
        for (int j = 0; j < SIZE; j++) {
            arr[j] = rand() % 1000; // generate new random numbers
        }
        insertionSort(arr, SIZE);
    }
    system("pause");
    return 0;
}