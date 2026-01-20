#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
  int topo;
  char items[MAX];
};

void inicializaPilha(struct Stack *s) {
  s->topo = -1;
} 

void push(struct Stack *s, char c) {
  if (s->topo == MAX - 1) {
    printf("Erro: Pilha cheia\n");
    return;
  }
  s->items[++(s->topo)] = c; 
}

char pop(struct Stack *s) {
  if (s->topo == -1) {
    printf("Erro: Pilha vazia\n");
    return '\0';
  }
  return s->items[(s->topo)--]; 
}

int palindromo(char *s) {
  struct Stack stack; 
  inicializaPilha(&stack);

  int tamanho = strlen(s); 
  char clean_string[tamanho];
  int j = 0;
  for (int i = 0; s[i]; i++) {
    if (isalnum(s[i])) {
      clean_string[j++] = tolower(s[i]);
    } 
  }
  clean_string[j] = '\0';

  for (int i = 0; clean_string[i]; i++) {
    push(&stack, clean_string[i]);
  }

  for (int i = 0; clean_string[i]; i++) {
    if (pop(&stack) != clean_string[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char *exemplos[] = {
      "A base do teto desaba.", "A diva em Argel alegra-me a vida.",
      "Adias a data da saida.", "Socorram-me, subi no onibus em Marrocos.",
      "O rato roeu a roupa do rei de Roma."};
  int num_exemplos = sizeof(exemplos) / sizeof(exemplos[0]);

  for (int i = 0; i < num_exemplos; i++) {
    printf("A frase \"%s\" e um palindromo? %s\n", exemplos[i],
           palindromo(exemplos[i]) ? "Sim\n" : "Nao\n");
  }
  system("pause");
  return 0;
}
