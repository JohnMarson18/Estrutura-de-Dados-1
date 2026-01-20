#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

ListaMultiEncadeada* criar_lista() {
    ListaMultiEncadeada* lista = (ListaMultiEncadeada*)malloc(sizeof(ListaMultiEncadeada));
    lista->head_2000 = NULL;
    lista->head_1990 = NULL;
    return lista;
}

void destruir_lista(ListaMultiEncadeada* lista) {
    Node *atual, *temp;

    atual = lista->head_2000;
    while (atual) {
        temp = atual;
        atual = atual->next_2000;
        free(temp);
    }

    atual = lista->head_1990;
    while (atual) {
        temp = atual;
        atual = atual->next_1990;
        free(temp);
    }

    free(lista);
}

Node* criar_node(const char* cidade, int pop_2000, int pop_1990) {
    Node* novo_node = (Node*)malloc(sizeof(Node));
    strcpy(novo_node->cidade, cidade);
    novo_node->pop_2000 = pop_2000;
    novo_node->pop_1990 = pop_1990;
    novo_node->next_2000 = NULL;
    novo_node->next_1990 = NULL;
    return novo_node;
}

void inserir(ListaMultiEncadeada* lista, const char* cidade, int pop_2000, int pop_1990) {
    Node* novo_node_2000 = criar_node(cidade, pop_2000, 0);
    Node* novo_node_1990 = criar_node(cidade, 0, pop_1990);

    // Inserir na lista de 2000
    if (!lista->head_2000 || lista->head_2000->pop_2000 > pop_2000) {
        novo_node_2000->next_2000 = lista->head_2000;
        lista->head_2000 = novo_node_2000;
    } else {
        Node* atual = lista->head_2000;
        while (atual->next_2000 && atual->next_2000->pop_2000 < pop_2000) {
            atual = atual->next_2000;
        }
        novo_node_2000->next_2000 = atual->next_2000;
        atual->next_2000 = novo_node_2000;
    }

    // Inserir na lista de 1990
    if (!lista->head_1990 || lista->head_1990->pop_1990 > pop_1990) {
        novo_node_1990->next_1990 = lista->head_1990;
        lista->head_1990 = novo_node_1990;
    } else {
        Node* atual = lista->head_1990;
        while (atual->next_1990 && atual->next_1990->pop_1990 < pop_1990) {
            atual = atual->next_1990;
        }
        novo_node_1990->next_1990 = atual->next_1990;
        atual->next_1990 = novo_node_1990;
    }
}

void imprimir_censo_2000(Node* head) {
    setlocale(LC_NUMERIC, "");

    Node* atual = head;
    while (atual) {
        printf("%s: %'d\n", atual->cidade, atual->pop_2000);
        atual = atual->next_2000;
    }
}

void imprimir_censo_1990(Node* head) {
    setlocale(LC_NUMERIC, "");

    Node* atual = head;
    while (atual) {
        printf("%s: %'d\n", atual->cidade, atual->pop_1990);
        atual = atual->next_1990;
    }
}

