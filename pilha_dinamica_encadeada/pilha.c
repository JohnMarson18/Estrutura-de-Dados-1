#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializar(Pilha* p) {
    p->top = NULL;
}

int estaVazia(Pilha* p) {
    return p->top == NULL;
}

void push(Pilha* p, int elemento) {
    No* new_node = (No*)malloc(sizeof(No));
    if (new_node == NULL) {
        printf("Erro: nao foi possivel alocar memoria.\n");
        return;
    }

    new_node->dado = elemento;
    new_node->prox = p->top;
    p->top = new_node;

    printf("Elemento %d empilhado com sucesso.\n", elemento);
}

int pop(Pilha* p, int* elemento) {
    if (estaVazia(p)) {
        printf("Erro: a pilha esta vazia.\n");
        return 0;
    }
    No* temp = p->top;
    *elemento = temp->dado;
    p->top = temp->prox;
    free(temp);
    return 1;
}

int top(Pilha* p, int* elemento) {
    if (estaVazia(p)) {
        printf("Erro: a pilha esta vazia.\n");
        return 0;
    }
    *elemento = p->top->dado;
    return 1;
}

void exibir(Pilha* p) {
    if (estaVazia(p)) {
        printf("A pilha esta vazia.\n");
        return;
    }
    printf("Elementos na pilha:\n");
    No* atual = p->top;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void inverterPilha(Pilha* p) {
    if (estaVazia(p) || p->top->prox == NULL) {
        return;
    }

    No *prev = NULL;
    No *current = p->top;
    No *next;

    while (current != NULL) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }

    p->top = prev;
}
