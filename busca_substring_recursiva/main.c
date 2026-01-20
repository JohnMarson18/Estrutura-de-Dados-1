#include <stdio.h>
#include <string.h>

void encontrarSubString(char *str, char *subStr, int indice) {
    int tamanhoStr = strlen(str);
    int tamanhoSubStr = strlen(subStr);

    if (indice + tamanhoSubStr > tamanhoStr) {
        return;  // Se não há espaço para a substring, termina recursão
    }

    // Verifica se a substring ocorre a partir do índice atual
    int i;
    for (i = 0; i < tamanhoSubStr; i++) {
        if (str[indice + i] != subStr[i]) {
            break;  // Se os caracteres não coincidem, para
        }
    }

    // Se a substring foi encontrada, imprime a posicao
    if (i == tamanhoSubStr) {
        printf("Substring encontrada na posicao: %d\n", indice);
    }

    // Chama a função recursivamente para o próximo índice
    encontrarSubString(str, subStr, indice + 1);
}

int main() {
    char str[100];
    char subStr[100];

    printf("Digite a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove a quebra de linha do fgets

    printf("Digite a substring a ser encontrada: ");
    fgets(subStr, sizeof(subStr), stdin);
    subStr[strcspn(subStr, "\n")] = '\0';  // Remove a quebra de linha do fgets

    printf("Procurando por '%s' em '%s'\n", subStr, str);

    encontrarSubString(str, subStr, 0);
    system("pause");
    return 0;
}
