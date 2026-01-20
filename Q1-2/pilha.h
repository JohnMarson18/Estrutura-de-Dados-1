#ifndef PILHA_H
#define PILHA_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* top;
} Pilha;

void inicializar(Pilha* p);
int estaVazia(Pilha* p);
void push(Pilha* p, int elemento);
int pop(Pilha* p, int* elemento);
int top(Pilha* p, int* elemento);
void exibir(Pilha* p);
void inverterPilha(Pilha* p);

#endif /* PILHA_H */
