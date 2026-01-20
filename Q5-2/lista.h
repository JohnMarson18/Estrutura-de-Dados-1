#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

typedef struct No {
    void* dado;
    struct No* prox;
} No;

typedef struct {
    No* cabecalho;
    size_t tamanhoDado; // Tamanho do dado armazenado
} ListaOrdenada;

void inicializarLista(ListaOrdenada* lista, size_t tamanhoDado);
void inserir(ListaOrdenada* lista, void* valor);
void removerItem(ListaOrdenada* lista, void* valor);
void imprimirLista(ListaOrdenada* lista, void (*imprimir)(void*));
void destruirLista(ListaOrdenada* lista);

#endif
