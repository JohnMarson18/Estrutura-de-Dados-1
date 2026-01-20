#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(ListaOrdenada* lista, size_t tamanhoDado) {
    lista->cabecalho = (No*)malloc(sizeof(No));
    if (lista->cabecalho == NULL) {
        printf("Erro: Não foi possível alocar memória para o cabeçalho da lista.\n");
        exit(EXIT_FAILURE);
    }
    lista->cabecalho->dado = NULL;
    lista->cabecalho->prox = NULL;
    lista->tamanhoDado = tamanhoDado;
}

void inserir(ListaOrdenada* lista, void* valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = malloc(lista->tamanhoDado);
    if (novoNo->dado == NULL) {
        printf("Erro: Não foi possível alocar memória para o dado do novo nó.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(novoNo->dado, valor, lista->tamanhoDado);

    No* anterior = lista->cabecalho;
    No* atual = lista->cabecalho->prox;

    while (atual != NULL && memcmp(atual->dado, valor, lista->tamanhoDado) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novoNo;
    novoNo->prox = atual;
}

void removerItem(ListaOrdenada* lista, void* valor) {
    No* anterior = lista->cabecalho;
    No* atual = lista->cabecalho->prox;

    while (atual != NULL && memcmp(atual->dado, valor, lista->tamanhoDado) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual->dado);
        free(atual);
        printf("Elemento removido com sucesso.\n");
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
}

void imprimirLista(ListaOrdenada* lista, void (*imprimir)(void*)) {
    No* atual = lista->cabecalho->prox;
    printf("Lista: ");
    while (atual != NULL) {
        imprimir(atual->dado);
        printf(" ");
        atual = atual->prox;
    }
    printf("\n");
}

void destruirLista(ListaOrdenada* lista) {
    No* atual = lista->cabecalho;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp->dado);
        free(temp);
    }
    lista->cabecalho = NULL;
}
