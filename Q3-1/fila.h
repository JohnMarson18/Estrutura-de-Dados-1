#ifndef FILA_H
#define FILA_H

#define MAX 10

typedef struct {
  int itens[MAX];
  int frente, tras;
  int contador;
} Fila;

void inicializar(Fila *f);
int vazia(Fila *f);
int cheia(Fila *f);
void inserir(Fila *f, int valor);
int remover(Fila *f);
void exibir(Fila *f);
int consultar_inicio(Fila *f);
void destruir_fila(Fila *f);

#endif /* FILA_H */
