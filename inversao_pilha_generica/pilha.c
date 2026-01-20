#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* inicializar() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (!pilha) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    pilha->topo = NULL;
    pilha->fundo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void push(Pilha* pilha, void* data) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (!novoNo) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->data = data;
    novoNo->next = NULL;
    if (!pilha->topo) {
        pilha->topo = novoNo;
        pilha->fundo = novoNo;
    } else {
        novoNo->next = pilha->topo;
        pilha->topo = novoNo;
    }
    pilha->tamanho++;
}

void* pop(Pilha* pilha) {
    if (!pilha->topo)
        return NULL;
    Node* temp = pilha->topo;
    void* data = temp->data;
    pilha->topo = temp->next;
    free(temp);
    pilha->tamanho--;
    return data;
}

void* top(Pilha* pilha) {
    if (!pilha->topo)
        return NULL;
    return pilha->topo->data;
}

void exibir(Pilha* pilha) {
    if (!pilha->topo) {
        printf("Pilha vazia.\n");
        return;
    }
    Node* atual = pilha->topo;
    printf("Topo da pilha: %d\n", *(int*)atual->data);
    printf("Elementos da pilha: ");
    while (atual) {
        printf("%d ", *(int*)atual->data);
        atual = atual->next;
    }
    printf("\n");
}

void inverter(Pilha* pilha) {
    Node* anterior = NULL;
    Node* atual = pilha->topo;
    Node* proximo = NULL;
    while (atual) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    pilha->topo = anterior;
    Node* temp = pilha->topo;
    while (temp->next) {
        temp = temp->next;
    }
    pilha->fundo = temp;
}
