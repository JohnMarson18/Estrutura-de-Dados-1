# Aplicação de Teste de Pilha (Interface)

## Descrição
Este módulo contém a interface de usuário (CLI) para testar as operações de uma Pilha. Ele apresenta um menu interativo que permite ao usuário empilhar, desempilhar e visualizar dados.

## O que o programa faz
1.  Exibe um menu interativo.
2.  Permite a inserção dinâmica de valores.
3.  Chama as funções da biblioteca de pilha (definidas em `pilha.h`).
4.  Inclui funcionalidade para inverter a ordem da pilha.

## Como foi feito
- Utiliza um loop infinito `while(1)` para manter o menu ativo.
- Usa `switch/case` para tratar as opções do usuário.
- Depende de uma implementação externa de `pilha.h` (como a da pasta Q1-2).

## Como Compilar
Deve ser compilado junto com a implementação da pilha:
```bash
gcc main.c ../Q1-2/pilha.c -o teste_pilha
```