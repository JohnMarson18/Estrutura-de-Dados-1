#ifndef Q2_H
#define Q2_H

typedef struct Conjunto Conjunto;

Conjunto* conjunto_create();
void conjunto_insert(Conjunto* conjunto, int element);
void conjunto_remove(Conjunto* conjunto, int element);
Conjunto* conjunto_union(Conjunto* conjunto1, Conjunto* conjunto2);
Conjunto* conjunto_intersection(Conjunto* conjunto1, Conjunto* conjunto2);
Conjunto* conjunto_difference(Conjunto* conjunto1, Conjunto* conjunto2);
int conjunto_contains(Conjunto* conjunto, int element);
int conjunto_min(Conjunto* conjunto);
int conjunto_max(Conjunto* conjunto);
int conjunto_equals(Conjunto* conjunto1, Conjunto* conjunto2);
void conjunto_print(Conjunto* conjunto);
void conjunto_destroy(Conjunto* conjunto);

#endif  // Q2_H