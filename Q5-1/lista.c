#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(ListaOrdenada* lista) {
    lista->cabecalho = (No*)malloc(sizeof(No));
    if (lista->cabecalho == NULL) {
        printf("Erro: Não foi possível alocar memória para o cabeçalho da lista.\n");
        exit(EXIT_FAILURE);
    }
    lista->cabecalho->dado = 0;
    lista->cabecalho->prox = NULL;
}

void inserir(ListaOrdenada* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;

    No* anterior = lista->cabecalho;
    No* atual = lista->cabecalho->prox;

    while (atual != NULL && atual->dado < valor) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novoNo;
    novoNo->prox = atual;
}

void removerItem(ListaOrdenada* lista, int valor) {
    No* anterior = lista->cabecalho;
    No* atual = lista->cabecalho->prox;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual);
        printf("Elemento %d removido com sucesso.\n", valor);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valor);
    }
}

void imprimirLista(ListaOrdenada* lista) {
    No* atual = lista->cabecalho->prox;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void destruirLista(ListaOrdenada* lista) {
    No* atual = lista->cabecalho;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->cabecalho = NULL;
}
