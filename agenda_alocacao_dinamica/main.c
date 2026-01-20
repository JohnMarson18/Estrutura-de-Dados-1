/* agenda.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda {
  char nome[40];
  char email[40];
  long long telefone;
} AGENDA;

void aloca(AGENDA **pAgenda, int *piEntradas);
void consulta(AGENDA *pAgenda, int iEntradas);
void qs_ordena(AGENDA pAgenda[], int left, int right);
void ordena(AGENDA pAgenda[], int iEntradas);
void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);

int main(void) {
  AGENDA *pAgenda;

  int iEntradas, op;
  iEntradas = 0;

  pAgenda = (AGENDA *)malloc(sizeof(AGENDA)); /* alocando espaco para a posicao
    0 do vetor */
  if (pAgenda == NULL) {
    printf("\nErro de alocacao de memoria.");
    exit(1);
  }

  do {
    fflush(stdin);
    printf("\n1 - Inclusao");
    printf("\n2 - Alteracao");
    printf("\n3 - Consulta");
    printf("\n4 - Excluir");
    printf("\n5 - Pesquisar");
    printf("\n9 - Sair");
    printf("\nEntre com uma opcao -> ");
    scanf("%d", &op);

    if (op == 1) {
      /* farei aqui para ilustrar algumas formas de manipular ponteiros */
      fflush(stdin);
      /* alocacao de ponteiros em funcoes requer trabalhar com ponteiros
      para ponteiros */
      aloca(&pAgenda, &iEntradas);
      printf("*** Inclusao ***");
      printf("\nEntre com o Nome:");
      /* forma 1 - endereco ponteiro inicial + x posicoes na memória
      quando se trabalhar com o endereco, deve-se usar -> */
      getchar();
      fgets(pAgenda[iEntradas].nome, sizeof(pAgenda[iEntradas].nome), stdin);
      fflush(stdin);

      printf("Entre com o email:");
      /* forma 2 - endereco ponteiro inicial + x posicoes na memória
      quando se trabalhar com ponteiro (conteúdo do endereco ou *),
      deve-se usar o . (ponto) */
      fgets(pAgenda[iEntradas].email, sizeof(pAgenda[iEntradas].email), stdin);
      fflush(stdin);
      printf("Entre com o telefone:");
      /* forma 3 - trabalhando como vetor */
      scanf(" %lld", &pAgenda[iEntradas].telefone);

      iEntradas++;
    } else if (op == 2) {
      alterar(pAgenda, iEntradas);
    } else if (op == 3) {
      /* se o vetor de estruturas vai ser somente lido
      nao é preciso passar ponteiro para ponteiro */
      ordena(pAgenda, iEntradas);
      consulta(pAgenda, iEntradas);
    } else if (op == 4) {
      ordena(pAgenda, iEntradas);
      excluir(&pAgenda, &iEntradas);
    } else if (op == 5) {
      ordena(pAgenda, iEntradas);
      pesquisar(pAgenda, iEntradas);
    }
  } while (op != 9);
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
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome)) != 0; i++)
    ;
  if (i >= iEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    printf("\n\tRegistro %d", i);
    printf("\n\tNome : %s", pAgenda[i].nome);
    printf("\n\tEmail : %s", pAgenda[i].email);
    printf("\n\tFone : %lld", pAgenda[i].telefone);
    printf("\n\tConirma a alteracao ?");
    op = getchar();
    if (op == 'S' || op == 's') {
      fflush(stdin);
      printf("\nEntre com o Nome:");
      /* forma 1 - endereco ponteiro inicial + x posicoes na memória
      quando se trabalhar com o endereco, deve-se usar -> */
      getchar();
      fgets(pAgenda[i].nome, sizeof(pAgenda[i].nome), stdin);
      fflush(stdin);

      printf("Entre com o email:");
      /* forma 2 - endereco ponteiro inicial + x posicoes na memória
      quando se trabalhar com ponteiro (conteúdo do endereco ou *),
      deve-se usar o . (ponto) */
      fgets(pAgenda[i].email, sizeof(pAgenda[i].email), stdin);
      fflush(stdin);

      printf("Entre com o telefone:");
      /* forma 3 - trabalhando como vetor */
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
  /* Uso a sintaxe (*pAgenda)[i].nome pelo fato de ser ponteiro de ponteiro.
  Os parênteses neste caso servem para “ixar” a primeira posicao da memória,
  pois a linguagem C tende a trabalhar com ponteiros de ponteiros como se fossem
  matrizes (que na prática sao ponteiros para ponteiros) */
  for (i = 0;
       i < *piEntradas && strncmp((*pAgenda)[i].nome, nome, strlen(nome)) != 0;
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
    printf("\n\tConirma a exclusao ?");
    op = getchar();
    if (op == 'S' || op == 's') {
      /* copio o último elemento para o elemento corrente */
      (*pAgenda)[i] = (*pAgenda)[(*piEntradas) - 1];

      (*piEntradas)--;
      /* excluo o último elemento com realoc */
      aloca(pAgenda, piEntradas);
    }
  }
}

void aloca(AGENDA **pAgenda, int *piEntradas) {
  (*pAgenda) =
      (AGENDA *)(realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA)));
  if (*pAgenda == NULL) {
    printf("\nErro de re-alocacao de memoria");
    exit(1);
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
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome)) != 0; i++)
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
      printf("\n\tProximo ?");
      op = getchar();
      i++;
      if (i >= iEntradas) {
        i = 0;
      }
    } while (op == 'S' || op == 's');
  }
}

void ordena(AGENDA pAgenda[], int iEntradas) {
  qs_ordena(pAgenda, 0, iEntradas - 1);
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