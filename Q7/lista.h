#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    char cidade[100];
    int pop_2000;
    int pop_1990;
    struct Node* next_2000;
    struct Node* next_1990;
} Node;

typedef struct ListaMultiEncadeada {
    Node* head_2000;
    Node* head_1990;
} ListaMultiEncadeada;

ListaMultiEncadeada* criar_lista();
void destruir_lista(ListaMultiEncadeada* lista);
Node* criar_node_2000(const char* cidade, int pop_2000);
Node* criar_node_1990(const char* cidade, int pop_1990);
void inserir(ListaMultiEncadeada* lista, const char* cidade, int pop_2000, int pop_1990);
void imprimir_censo_2000(Node* head);
void imprimir_censo_1990(Node* head);

#endif // LISTA_H