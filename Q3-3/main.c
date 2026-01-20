#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void imprimir_valor(void *valor, Tipo tipo) {
  if (tipo == INT) {
    printf("%d\n", *(int *)valor);
  } else if (tipo == FLOAT) {
    printf("%.2f\n", *(float *)valor);
  }
}

int main() {
  Fila fila;
  inicializar(&fila);

  int num1 = 1, num3 = 3;
  float num2 = 2.5f, num4 = 4.5f;
  inserir(&fila, &num1, INT);
  exibir(&fila);
  inserir(&fila, &num2, FLOAT);
  exibir(&fila);
  inserir(&fila, &num3, INT);
  exibir(&fila);
  inserir(&fila, &num4, FLOAT);

  exibir(&fila);

  void *elemento; 

 
  while (!vazia(&fila)) {
    printf("\nRemovendo elementos:");
    elemento = remover(&fila);
                               
    if (elemento != NULL) {
      imprimir_valor(elemento,  ((No *)elemento)->tipo);
    }
    exibir(&fila);
  }
  destruir_fila(&fila);
  system("pause");
  return 0;
}
