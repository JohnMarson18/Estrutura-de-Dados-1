#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p);
int estaCheia(Pilha* p);
int estaVazia(Pilha* p);
int push(Pilha* p, int quantidade);
int pop(Pilha* p, int* elemento);
int top(Pilha* p, int* elemento);
void exibir(Pilha* p);
void inverterPilha(Pilha* p);

#endif