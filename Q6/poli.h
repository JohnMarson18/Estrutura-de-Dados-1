#ifndef POLI_H
#define POLI_H

typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
} Node;

void inserir(Node** poli, int coef, int exp);
Node* soma(Node* poli1, Node* poli2);
void exibir(Node* poli);
void destruir(Node* poli);
Node* confirma();

#endif /* POLI_H */
