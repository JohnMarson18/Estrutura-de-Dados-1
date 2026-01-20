#ifndef FILA_H
#define FILA_H

typedef struct No {
  int dado;
  struct No *prox;
} No;

typedef struct {
  No *inicio;
  No *fim;
  int contador;
} Fila;

void inicializar(Fila *f);
int vazia(Fila *f);
void inserir(Fila *f, int valor);
int remover(Fila *f);
void exibir(Fila *f);
int consultar_inicio(Fila *f);
void destruir_fila(Fila *f);

#endif /* FILA_H */
