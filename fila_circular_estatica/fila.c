#include "fila.h"
#include <stdio.h>

void inicializar(Fila *f) {
  f->frente = 0;
  f->tras = -1;
  f->contador = 0;
}

int vazia(Fila *f) { return f->contador == 0; }

int cheia(Fila *f) { return f->contador == MAX; }

void inserir(Fila *f, int valor) {
  if (!cheia(f)) {
    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = valor;
    f->contador++;
  } else {
    printf("Erro: A fila está cheia.\n");
  }
}

int remover(Fila *f) {
  if (!vazia(f)) {
    int valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->contador--;
    return valor;
  } else {
    printf("Erro: A fila esta vazia.\n");
    return -1;
  }
}

void exibir(Fila *f) {
  if (!vazia(f)) {
    printf("Fila: ");
    int i = f->frente;
    int count = 0;
    while (count < f->contador) {
      printf("%d ", f->itens[i]);
      i = (i + 1) % MAX;
      count++;
    }
    printf("\n");
  } else {
    printf("Fila vazia.\n");
  }
}

int consultar_inicio(Fila *f) {
  if (!vazia(f)) {
    return f->itens[f->frente];
  } else {
    printf("Erro: A fila esta vazia.\n");
    return -1;
  }
}

void destruir_fila(Fila *f) {
  f->frente = 0;
  f->tras = -1;
  f->contador = 0;
}
