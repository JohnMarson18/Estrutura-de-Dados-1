#include <stdio.h>
#include <stdlib.h>
#include "poli.h"

Node* criarNode(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void inserir(Node** poli, int coef, int exp) {
    Node* newNode = criarNode(coef, exp);
    if (*poli == NULL || (*poli)->exp < exp) {
        newNode->next = *poli;
        *poli = newNode;
    } else {
        Node* temp = *poli;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        if (temp->exp == exp) {
            temp->coef += coef;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

Node* soma(Node* poli1, Node* poli2) {
    Node* result = NULL;
    while (poli1 != NULL && poli2 != NULL) {
        if (poli1->exp > poli2->exp) {
            inserir(&result, poli1->coef, poli1->exp);
            poli1 = poli1->next;
        } else if (poli1->exp < poli2->exp) {
            inserir(&result, poli2->coef, poli2->exp);
            poli2 = poli2->next;
        } else {
            inserir(&result, poli1->coef + poli2->coef, poli1->exp);
            poli1 = poli1->next;
            poli2 = poli2->next;
        }
    }
    while (poli1 != NULL) {
        inserir(&result, poli1->coef, poli1->exp);
        poli1 = poli1->next;
    }
    while (poli2 != NULL) {
        inserir(&result, poli2->coef, poli2->exp);
        poli2 = poli2->next;
    }
    return result;
}

void exibir(Node* poli) {
    while (poli != NULL) {
        printf("%dx^%d", poli->coef, poli->exp);
        poli = poli->next;
        if (poli != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void destruir(Node* poli) {
    Node* temp;
    while (poli != NULL) {
        temp = poli;
        poli = poli->next;
        free(temp);
    }
}

Node* confirma() {
    Node* poli = NULL;
    int n, coef, exp;
    char confirm;

    do {
        poli = NULL;
        printf("Digite o numero de termos do polinomio: ");
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            printf("Digite o coeficiente do termo %d: ", i + 1);
            scanf("%d", &coef);
            printf("Digite o expoente do termo %d: ", i + 1);
            scanf("%d", &exp);
            inserir(&poli, coef, exp);
        }

        printf("Polinomio digitado: ");
        exibir(poli);

        printf("Deseja confirmar este polinomio? (s/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'n') {
            destruir(poli);
        }
    } while (confirm == 'n');

    return poli;
}
