#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->contador = 0;
}

int vazia(Fila *f) {
    return f->contador == 0;
}

void inserir(Fila *f, void *valor, Tipo tipo) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha ao alocar memoria para novo no.\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->tipo = tipo;
    novoNo->prox = NULL;

    if (vazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->prox = novoNo;
    }
    f->fim = novoNo;
    f->contador++;
}

void *remover(Fila *f) {
    if (vazia(f)) {
        printf("Erro: A fila esta vazia.\n");
        return NULL;
    }
    No *temp = f->inicio;
    void *valor = temp->dado;
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
        if (atual->tipo == INT) {
            printf("%d ", *(int *)atual->dado);
        } else if (atual->tipo == FLOAT) {
            printf("%.2f ", *(float *)atual->dado);
        }
        atual = atual->prox;
    }
    printf("\n");
}

void *consultar_inicio(Fila *f) {
    if (vazia(f)) {
        printf("Erro: A fila esta vazia.\n");
        return NULL;
    }
    return f->inicio->dado;
}

void destruir_fila(Fila *f) {
    No *atual = f->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp->dado); 
        free(temp);      
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->contador = 0;
}

