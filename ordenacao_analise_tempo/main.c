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
  int n;
  n=50000;
  int vet[n], i;

  srand(time(NULL));


  int bubble_sorted[n], selection_sorted[n], insertion_sorted[n];
  clock_t start, end;
  double elapsed_time;

  for (int i = 0; i < n; i++) {
    bubble_sorted[i] = vet[i];
  }
  
  start = clock();  //O tempo de início (start) é registrado usando a função clock().
  bubbleSort(bubble_sorted, n);
  end = clock(); //O tempo de fim (end) é registrado usando novamente a função clock().
  elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;  //O tempo decorrido é calculado subtraindo o tempo de fim pelo tempo de início. Este valor é então convertido para milissegundos dividindo pelo número de clocks por segundo (CLOCKS_PER_SEC) e multiplicando por 1000.0.

  printf("\nBubbleSort: %.2f milliseconds\n", elapsed_time);
  
  printf("\n");

  for (int i = 0; i < n; i++) {
      selection_sorted[i] = vet[i];
  }
  start = clock();
  selectionSort(selection_sorted, n);
  end = clock();
  elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
  printf("\nSelectionSort: %.2f milliseconds\n", elapsed_time);
 
  printf("\n");


    for (int i = 0; i < n; i++) {
      insertion_sorted[i] = vet[i];
  }

   start = clock();
  insertionSort(insertion_sorted, n);
   end = clock();
  elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;
  printf("\nInsertionSort: %.2f milliseconds\n", elapsed_time);
  
  printf("\n");
  system("pause");
  return 0;
}