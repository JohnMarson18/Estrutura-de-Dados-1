#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha* pilha = inicializar();

    int numeros[] = {1, 2, 3, 4, 5, 6, 7}; 
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < tamanho; i++) {
        push(pilha, &numeros[i]);
    }

    printf("Pilha original:\n");
    exibir(pilha);

    printf("\n");
    inverter(pilha);

    printf("\nPilha invertida:\n");
    exibir(pilha);
    system("pause");
    return 0;
    
}
