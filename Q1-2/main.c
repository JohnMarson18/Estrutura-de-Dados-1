#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void clear() {
    printf("\033[2J\033[H");
}

int main() {
    Pilha p;
    inicializar(&p);

    int escolha, elemento, quantidade, sucesso;

    while (1) {
        clear();
        printf("Escolha uma operacao:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Ver topo\n");
        printf("4. Exibir pilha\n");
        printf("5. Inverter pilha\n");
        printf("6. Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                push(&p, elemento);
                break;

            case 2:
                if (pop(&p, &elemento)) {
                    printf("elemento %d desempilhado com sucesso.\n", elemento);
                }
                break;

            case 3:
                if (top(&p, &elemento)) {
                    printf("elemento no topo: %d\n", elemento);
                }
                break;

            case 4:
                exibir(&p);
                break;

            case 5:
                inverterPilha(&p);
                printf("Pilha invertida com sucesso.\n");
                break;

            case 6:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        getchar();
        getchar();
    }

    return 0;
}
