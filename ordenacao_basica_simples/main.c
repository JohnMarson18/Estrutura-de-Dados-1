#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(void) {
 int vet[10], i;

  srand(time(NULL));

  printf("Vetor não ordenado: \n");
  for (i=0; i<10; i++){
    vet[i]=rand()%100;
    printf("%d ", vet[i]);
  }

  printf("\n");

  int bubble_sorted[10];
  for (int i = 0; i < 10; i++) {
      bubble_sorted[i] = vet[i];
  }
  bubbleSort(bubble_sorted, 10);
  printf("\nBubbleSort:\n ");
  for (int i = 0; i < 10; i++) {
      printf("%d ", bubble_sorted[i]);
  }
  printf("\n");

  int selection_sorted[10];
  for (int i = 0; i < 10; i++) {
      selection_sorted[i] = vet[i];
  }
  selectionSort(selection_sorted, 10);
  printf("\nSelectionSort:\n ");
  for (int i = 0; i < 10; i++) {
      printf("%d ", selection_sorted[i]);
  }
  printf("\n");

  int insertion_sorted[10];
  for (int i = 0; i < 10; i++) {
      insertion_sorted[i] = vet[i];
  }
  insertionSort(insertion_sorted, 10);
  printf("\nInsertionSort:\n ");
  for (int i = 0; i < 10; i++) {
      printf("%d ", insertion_sorted[i]);
  }
  printf("\n");
  system("pause");
  return 0;
}