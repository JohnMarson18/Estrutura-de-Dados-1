#ifndef FILA_H
#define FILA_H

typedef enum {
    INT,
    FLOAT
} Tipo;

typedef struct No {
    void *dado;
    Tipo tipo;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int contador;
} Fila;

void inicializar(Fila *f);
int vazia(Fila *f);
void inserir(Fila *f, void *valor, Tipo tipo);
void *remover(Fila *f);
void exibir(Fila *f);
void *consultar_inicio(Fila *f); 
void destruir_fila(Fila *f);     
int cheia(); 

#endif /* FILA_H */
