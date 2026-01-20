#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Fila *f) {
  f->inicio = NULL;
  f->fim = NULL;
  f->contador = 0;
}

int vazia(Fila *f) { return f->contador == 0; }

void inserir(Fila *f, int valor) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro: Falha ao alocar memoria para novo no.\n");
    return;
  }
  novoNo->dado = valor;
  novoNo->prox = NULL;

  if (vazia(f)) {
    f->inicio = novoNo;
  } else {
    f->fim->prox = novoNo;
  }
  f->fim = novoNo;
  f->contador++;
}

int remover(Fila *f) {
  if (vazia(f)) {
    printf("Erro: A fila esta vazia.\n");
    return -1;
  }
  No *temp = f->inicio;
  int valor = temp->dado;
  f->inicio = temp->prox;
  free(temp);
  f->contador--;
  return valor;
}

void exibir(Fila *f) {
  if (vazia(f)) {
    printf("Fila vazia.\n");
    return;
  }
  printf("Fila: ");
  No *atual = f->inicio;
  while (atual != NULL) {
    printf("%d ", atual->dado);
    atual = atual->prox;
  }
  printf("\n");
}

int consultar_inicio(Fila *f) {
  if (!vazia(f)) {
    return f->inicio->dado;
  } else {
    printf("Erro: A fila esta vazia.\n");
    return -1;
  }
}

void destruir_fila(Fila *f) {
  No *atual = f->inicio;
  while (atual != NULL) {
    No *temp = atual;
    atual = atual->prox;
    free(temp);
  }
  f->inicio = NULL;
  f->fim = NULL;
  f->contador = 0;
}

// Exibe o cabeçalho da fila
void exibir_cabecalho(Fila *f) {
printf("\nCabeçalho da Fila:\n");
if (f->inicio != NULL) {
printf(" Início: %d\n", f->inicio->dado);
} else {
printf(" Início: NULL\n");
}

if (f->fim != NULL) {
printf(" Fim: %d\n", f->fim->dado);
} else {
printf(" Fim: NULL\n");
}
  printf(" Contador: %d\n\n", f->contador);
  }
 