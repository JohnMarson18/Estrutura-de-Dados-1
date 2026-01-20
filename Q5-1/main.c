#include "lista.h"
#include <stdio.h>

void limparTela() {
    printf("\033[2J\033[H");
}

int main() {
    int escolha, valor, qtdeElementos, i;
    ListaOrdenada minhaLista;

    inicializarLista(&minhaLista);

    while (1) {
        limparTela();
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Ver lista\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite quantos elementos deseja inserir: ");
                scanf("%d", &qtdeElementos);
                for (i = 0; i < qtdeElementos; i++) {
                    printf("Digite o valor do elemento %d: ", i + 1);
                    scanf("%d", &valor);
                    inserir(&minhaLista, valor);
                }
                printf("Elementos inseridos com sucesso.\n");
                break;
            case 2:
                printf("\n");
                imprimirLista(&minhaLista);
                printf("\n");
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerItem(&minhaLista, valor);
                break;
            case 3:
                imprimirLista(&minhaLista);
                break;
            case 4:
                destruirLista(&minhaLista);
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
        getchar();
        getchar();
    }

    return 0;
}
