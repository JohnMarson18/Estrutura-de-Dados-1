#include <stdio.h>
#include <stdlib.h>
#include "poli.h"

void clear() {
    printf("\033[2J\033[H");
}

int main() {
    Node* poli1 = NULL;
    Node* poli2 = NULL;

    printf("Entrada do primeiro polinomio:\n");
    poli1 = confirma();
    clear();

    printf("Entrada do segundo polinomio:\n");
    poli2 = confirma();
    clear();

    printf("Primeiro polinomio: ");
    exibir(poli1);
    printf("Segundo polinomio: ");
    exibir(poli2);

    Node* sum = soma(poli1, poli2);
    printf("Soma dos polinomios: ");
    exibir(sum);

    destruir(poli1);
    destruir(poli2);
    destruir(sum);
    system("pause");
    return 0;
}
