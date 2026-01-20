#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void aloca(AGENDA **pAgenda, int *piEntradas) {
  (*pAgenda) =
      (AGENDA *)(realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA)));
  if (*pAgenda == NULL) {
    printf("\nErro de re-alocacao de memoria");
    exit(1);
  }
}

void consulta(AGENDA *pAgenda, int iEntradas) {
  int i;
  for (i = 0; i < iEntradas; i++) {
    printf("\n\nRegistro %d", i);
    printf("\n\tNome: %s", pAgenda[i].nome);
    printf("\n\tEmails: %s", pAgenda[i].email);
    printf("\n\tTelefone: %lld", pAgenda[i].telefone);
    getchar();
  }
}

void alterar(AGENDA *pAgenda, int iEntradas) {
  char op;
  int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  fflush(stdin);
  getchar();
  fgets(nome, sizeof(nome), stdin);

  for (i = 0;
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome))!= 0; i++)
    ;
  if (i >= iEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    printf("\n\tRegistro %d", i);
    printf("\n\tNome : %s", pAgenda[i].nome);
    printf("\n\tEmail : %s", pAgenda[i].email);
    printf("\n\tFone : %lld", pAgenda[i].telefone);
    printf("\n\tConirma a alteracao?");
    op = getchar();
    if (op == 'S' || op == 's') {
      fflush(stdin);
      printf("\nEntre com o Nome:");
      getchar();
      fgets(pAgenda[i].nome, sizeof(pAgenda[i].nome), stdin);
      fflush(stdin);

      printf("Entre com o email:");
      fgets(pAgenda[i].email, sizeof(pAgenda[i].email), stdin);
      fflush(stdin);

      printf("Entre com o telefone:");
      scanf(" %lld", &pAgenda[i].telefone);
      fflush(stdin);
    }
  }
}

void excluir(AGENDA **pAgenda, int *piEntradas) {
  char op;
  int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  fflush(stdin);
  getchar();
  fgets(nome, sizeof(nome), stdin);
  for (i = 0;
       i < *piEntradas && strncmp((*pAgenda)[i].nome, nome, strlen(nome))!= 0;
       i++)
    ;
  if (i >= *piEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    fflush(stdin);
    printf("\n\tRegistro %d", i);
    printf("\n\tNome : %s", (*pAgenda)[i].nome);
    printf("\n\tEmail : %s", (*pAgenda)[i].email);
    printf("\n\tFone : %lld", (*pAgenda)[i].telefone);
    printf("\n\tConirma a exclusao?");
    op = getchar();
    if (op == 'S' || op == 's') {
      (*pAgenda)[i] = (*pAgenda)[(*piEntradas) - 1];

      (*piEntradas)--;
      aloca(pAgenda, piEntradas);
    }
  }
}

void pesquisar(AGENDA *pAgenda, int iEntradas) {
  char op;
int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  fflush(stdin);
  getchar();
  fgets(nome, sizeof(nome), stdin);

  for (i = 0;
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome))!= 0; i++)
    ;
  if (i >= iEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    do {
      fflush(stdin);
      printf("\n\n\tRegistro %d", i);
      printf("\n\tNome : %s", pAgenda[i].nome);
      printf("\n\tEmail : %s", pAgenda[i].email);
      printf("\n\tFone : %lld", pAgenda[i].telefone);
      printf("\n\tProximo?");
      op = getchar();
      i++;
      if (i >= iEntradas) {
        i = 0;
      }
    } while (op == 'S' || op == 's');
  }
}

void qs_ordena(AGENDA pAgenda[], int left, int right) {
  register int i, j;
  char *x;
  AGENDA t;

  i = left;
  j = right;
  x = pAgenda[(left + right) / 2].nome;

  do {
    while (strcmp(pAgenda[i].nome, x) < 0 && i < right)
      i++;
    while (strcmp(pAgenda[j].nome, x) > 0 && j > left)
      j--;
    if (i <= j) {
      t = pAgenda[i];
      pAgenda[i] = pAgenda[j];
      pAgenda[j] = t;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j)
    qs_ordena(pAgenda, left, i);
  if (i < right)
    qs_ordena(pAgenda, i, right);
}

void ordena(AGENDA pAgenda[], int iEntradas) {
  qs_ordena(pAgenda, 0, iEntradas - 1);
}