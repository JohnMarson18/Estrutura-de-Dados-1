#include <stdio.h>
#include <stdlib.h>
#include "Q2.h"

struct Conjunto {
    int* elements;
    int size;
    int capacity;
};

Conjunto* conjunto_create() {
    Conjunto* conjunto = malloc(sizeof(Conjunto));
    conjunto->elements = malloc(sizeof(int) * 10); // inicialmente, capacidade de 10 elementos
    conjunto->size = 0;
    conjunto->capacity = 10;
    return conjunto;
}

void conjunto_insert(Conjunto* conjunto, int element) {
    if (conjunto->size == conjunto->capacity) {
        conjunto->capacity *= 2;
        int* new_elements = realloc(conjunto->elements, sizeof(int) * conjunto->capacity);
        if (!new_elements) {
            free(conjunto->elements);
            free(conjunto);
            printf("Erro: realloc falhou\n");
            exit(1);
        }
        conjunto->elements = new_elements;
    }
    conjunto->elements[conjunto->size++] = element;
}

void conjunto_add_unique(Conjunto* conjunto, int element) {
    if (!conjunto_contains(conjunto, element)) {
        conjunto_insert(conjunto, element);
    }
}

Conjunto* conjunto_union(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* union_conjunto = conjunto_create();
    int i;
    for (i = 0; i < conjunto1->size; i++) {
        conjunto_add_unique(union_conjunto, conjunto1->elements[i]);
    }
    for (i = 0; i < conjunto2->size; i++) {
        conjunto_add_unique(union_conjunto, conjunto2->elements[i]);
      
    }
    return union_conjunto;
}

Conjunto* conjunto_intersection(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* intersection_conjunto = conjunto_create();
    int i;
    for (i = 0; i < conjunto1->size; i++) {
        int element = conjunto1->elements[i];
        int found = 0;
        int j;
        for (j = 0; j < conjunto2->size; j++) {
            if (conjunto2->elements[j] == element) {
                found = 1;
                break;
            }
        }
        if (found) {
            conjunto_insert(intersection_conjunto, element);
        }
    }
    return intersection_conjunto;
}

Conjunto* conjunto_difference(Conjunto* conjunto1, Conjunto* conjunto2) {
    Conjunto* difference_conjunto = conjunto_create();
    int i;
    for (i = 0; i < conjunto1->size; i++) {
        int element = conjunto1->elements[i];
        int found = 0;
        int j;
        for (j = 0; j < conjunto2->size; j++) {
            if (conjunto2->elements[j] == element) {
                found = 1;
                break;
            }
        }
        if (!found) {
            conjunto_insert(difference_conjunto, element);
        }
    }
    return difference_conjunto;
}

int conjunto_contains(Conjunto* conjunto, int element) {
    int i;
    for (i = 0; i < conjunto->size; i++) {
        if(conjunto->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

int conjunto_min(Conjunto* conjunto) {
    int min = conjunto->elements[0];
    int i;
    for (i = 1; i < conjunto->size; i++) {
        if (conjunto->elements[i]< min) {
            min = conjunto->elements[i];
        }
    }
    return min;
}

int conjunto_max(Conjunto* conjunto) {
    int max = conjunto->elements[0];
    int i;
    for (i = 1; i < conjunto->size; i++) {
        if (conjunto->elements[i] > max) {
            max = conjunto->elements[i];
        }
    }
    return max;
}

int conjunto_equals(Conjunto* conjunto1, Conjunto* conjunto2) {
    if (conjunto1->size != conjunto2->size) {
        return 0;
    }
    int i;
    for (i = 0; i < conjunto1->size; i++) {
        if (!conjunto_contains(conjunto2, conjunto1->elements[i])) {
            return 0;
        }
    }
    return 1;
}

void conjunto_print(Conjunto* conjunto) {
    int i;
    printf("{");
    for (i = 0; i < conjunto->size; i++) {
        printf("%d", conjunto->elements[i]);
        if (i < conjunto->size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void conjunto_destroy(Conjunto* conjunto) {
    free(conjunto->elements);
    free(conjunto);
}