#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Fila fila;
  inicializar(&fila);

  inserir(&fila, 1);
  exibir(&fila);
  inserir(&fila, 2);
  exibir(&fila);
  inserir(&fila, 3);
  exibir(&fila);
  inserir(&fila, 4);
  exibir(&fila);
  inserir(&fila, 5);
  exibir(&fila);
  exibir_cabecalho(&fila);

  for (int i = 0; i < 5; i++) {
    printf("\nRemovendo o elemento da fila: %d\n", remover(&fila));
    exibir(&fila);
  }

  destruir_fila(&fila);
  system("pause");
  return 0;
}
