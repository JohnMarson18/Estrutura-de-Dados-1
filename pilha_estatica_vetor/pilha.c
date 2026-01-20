#include <stdio.h>
#include "pilha.h"

void inicializar(Pilha* p) {
    p->topo = -1;
}

int estaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

int estaVazia(Pilha* p) {
    return p->topo == -1;
}

int push(Pilha* p, int quantidade) {
    int elemento;
    int sucesso = 1;
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &elemento);
        if (estaCheia(p)) {
            printf("Erro: a pilha esta cheia.\n");
            sucesso = 0;
            break;
        }
        p->dados[++(p->topo)] = elemento;
    }
    if (sucesso) {
        printf("%d elementos inseridos com sucesso.\n", quantidade);
    }
    return sucesso;
}

int pop(Pilha* p, int* elemento) {
    if (estaVazia(p)) {
        printf("Erro: a pilha esta vazia.\n");
        return 0;
    }
    *elemento = p->dados[(p->topo)--];
    return 1;
}

int top(Pilha* p, int* elemento) {
    if (estaVazia(p)) {
        printf("Erro: a pilha esta vazia.\n");
        return 0;
    }
    *elemento = p->dados[p->topo];
    return 1;
}

void exibir(Pilha* p) {
    if (estaVazia(p)) {
        printf("A pilha esta vazia.\n");
        return;
    }
    printf("Elementos na pilha:\n");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void inverterPilha(Pilha* p) {
    int temp[MAX]; 
    int i = 0;
    while (!estaVazia(p)) {
        pop(p, &temp[i]);
        i++;
    }
    for (int j = 0; j < i; j++) {
        p->dados[j] = temp[j]; 
    }
    p->topo = i - 1;
}

