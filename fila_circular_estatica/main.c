#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  Fila fila;
  inicializar(&fila);

  inserir(&fila, 10);
  exibir(&fila);
  inserir(&fila, 20);
  exibir(&fila);
  inserir(&fila, 30);
  exibir(&fila);
  inserir(&fila, 40);
  exibir(&fila);
  inserir(&fila, 50);

  exibir(&fila);
  for (i = 0; i < 5; i++) {
    printf("\nElemento removido: %d\n", remover(&fila));
    exibir(&fila);
  }
  destruir_fila(&fila);
  system("pause");
  return 0;
}
