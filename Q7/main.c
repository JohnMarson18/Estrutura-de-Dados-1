#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    setlocale(LC_NUMERIC, "");
    ListaMultiEncadeada* lista = criar_lista();

    inserir(lista, "Nova York", 21199865, 19549649);
    inserir(lista, "Los Angeles", 16373645, 14531529);
    inserir(lista, "Chicago", 9157540, 8239820);
    inserir(lista, "Washington", 7608070, 6727050);
    inserir(lista, "Sao Francisco", 7039362, 6253311);
    inserir(lista, "Philadelphia", 6188463, 5892937);
    inserir(lista, "Boston", 5819100, 5455403);
    inserir(lista, "Detroit", 5456428, 5187171);
    inserir(lista, "Dallas", 5221801, 4037282);
    inserir(lista, "Houston", 4669571, 3731131);
    inserir(lista, "Atlanta", 4112198, 2959950);
    inserir(lista, "Miami", 3876380, 3192582);
    inserir(lista, "Seattle", 3554760, 2970328);
    inserir(lista, "Phoenix", 3251876, 2238480);
    inserir(lista, "Minneapolis", 2968806, 2538834);
    inserir(lista, "Cleveland", 2945831, 2859644);
    inserir(lista, "San Diego", 2813833, 2498016);
    inserir(lista, "St. Luis", 2603607, 2492525);
    inserir(lista, "Denver", 2581506, 1980140);
    inserir(lista, "San Juan", 2450292, 2270808);

    printf("Censo 2000:\n\n");
    imprimir_censo_2000(lista->head_2000);
    printf("\nCenso 1990:\n\n");
    imprimir_censo_1990(lista->head_1990);

    destruir_lista(lista);
    system("pause");
    return 0;
}