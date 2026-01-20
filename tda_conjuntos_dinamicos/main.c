#include <stdio.h>
#include "Q2.h"

Conjunto* criar_conjunto_usuario() {
    int tamanho;
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &tamanho);

    Conjunto* conjunto = conjunto_create();

    for (int i = 0; i < tamanho; i++) {
        int elemento;
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &elemento);
        conjunto_insert(conjunto, elemento);
    }

    return conjunto;
}

int main() {
  printf("CONJUNTO 1\n");
  Conjunto* conjunto1 = criar_conjunto_usuario();
  printf("CONJUNTO 2\n");
  Conjunto* conjunto2 = criar_conjunto_usuario();
  
    // Realizando operações nos conjuntos
    Conjunto* union_conjunto = conjunto_union(conjunto1, conjunto2);
    Conjunto* intersection_conjunto = conjunto_intersection(conjunto1, conjunto2);
    Conjunto* difference_conjunto = conjunto_difference(conjunto1, conjunto2);

    // Imprimindo os conjuntos
    printf("Conjunto 1: ");
    conjunto_print(conjunto1);
    printf("Conjunto 2: ");
    conjunto_print(conjunto2);
    printf("Uniao: ");
    conjunto_print(union_conjunto);
    printf("Intersecao: ");
    conjunto_print(intersection_conjunto);
    printf("Diferenca: ");
    conjunto_print(difference_conjunto);

    // Realizando testes nos conjuntos
    printf("Conjunto 1 contem 2? %s\n", conjunto_contains(conjunto1, 2) ? "Sim" : "Nao");
    printf("Menor valor do conjunto 1: %d\n", conjunto_min(conjunto1));
    printf("Maior valor do conjunto 2: %d\n", conjunto_max(conjunto2));
    printf("Conjuntos iguais? %s\n", conjunto_equals(conjunto1, conjunto2) ? "Sim" : "Nao");

    // Destruindo os conjuntos
    conjunto_destroy(conjunto1);
    conjunto_destroy(conjunto2);
    conjunto_destroy(union_conjunto);
    conjunto_destroy(intersection_conjunto);
    conjunto_destroy(difference_conjunto);

    return 0;
}