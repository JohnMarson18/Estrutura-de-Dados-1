#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* cabecalho;
} ListaOrdenada;

void inicializarLista(ListaOrdenada* lista);
void inserir(ListaOrdenada* lista, int valor);
void removerItem(ListaOrdenada* lista, int valor);
void imprimirLista(ListaOrdenada* lista);
void destruirLista(ListaOrdenada* lista);

#endif
