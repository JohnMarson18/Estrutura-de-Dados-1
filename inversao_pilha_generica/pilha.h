#ifndef PILHA_H
#define PILHA_H

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* topo;
    Node* fundo;
    int tamanho;
} Pilha;

Pilha* inicializar();
void push(Pilha* pilha, void* data);
void* pop(Pilha* pilha);
void* top(Pilha* pilha);
void exibir(Pilha* pilha);
void inverter(Pilha* pilha);

#endif /* PILHA_H */
