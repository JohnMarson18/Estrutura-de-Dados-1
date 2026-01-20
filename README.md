# 📚 Estruturas de Dados e Algoritmos em C

Este repositório reúne a resolução completa de exercícios práticos da disciplina de **Estrutura de Dados I**. O projeto abrange desde o gerenciamento fundamental de memória e TADs até a implementação de estruturas complexas e análise de performance de algoritmos de ordenação.

O código foi desenvolvido com foco em modularização, boas práticas de ponteiros e manipulação eficiente de dados.

---

## 👨‍💻 Autores

* **Paulo Fernando Pereira Junior**
* **Maria Luiza Souza**

### 🎓 Orientação Acadêmica
* **Professor:** Fermin Alfredo Tang Montane
* **Disciplina:** Estrutura de Dados I

---

## 📂 Estrutura do Projeto

O repositório está organizado por tópicos. Abaixo, o detalhamento de cada implementação:

### 💾 1. Alocação Dinâmica e TADs

Exercícios focados no uso de `malloc`, `realloc` e modularização de código.

| Diretório | Descrição | Destaques Técnicos |
| :--- | :--- | :--- |
| `/agenda_alocacao_dinamica` | Agenda de contatos com redimensionamento automático. | Uso de `realloc` para aumentar a capacidade do vetor dinamicamente[cite: 37]. |
| `/agenda_tad_modularizada` | Versão da agenda separada em interface (`.h`) e implementação (`.c`). | Aplicação do conceito de **Tipo Abstrato de Dados (TAD)**[cite: 84]. |
| `/tda_conjuntos_dinamicos` | Implementação da estrutura matemática de Conjuntos. | Operações de União, Interseção e Diferença usando vetores dinâmicos[cite: 106, 112]. |

### 🧱 2. Estruturas Lineares (Pilhas e Filas)

Implementações estáticas (vetor) e dinâmicas (encadeadas).

| Diretório | Descrição | Destaques Técnicos |
| :--- | :--- | :--- |
| `/pilha_estatica_vetor` | Pilha básica usando array fixo. | Controle de índice de topo. |
| `/pilha_dinamica_encadeada` | Pilha que cresce conforme a demanda. | Alocação dinâmica de nós. |
| `/verificador_palindromos` | Validador de frases palíndromas. | Uso de pilha para inverter e comparar caracteres. |
| `/fila_circular_estatica` | Fila otimizada em vetor. | Aritmética modular para reaproveitamento de índices. |
| `/fila_heterogenea_tipos_mistos` | Fila genérica para múltiplos tipos. | Uso de `void*` e `enum` para guardar `int` e `float` juntos. |
| `/calculadora_notacao_prefixa` | Calculadora de expressões polonesas. | Avaliação de expressões matemáticas via Fila/Pilha. |

### 🔗 3. Listas Encadeadas e Aplicações

Manipulação avançada de nós e ponteiros.

| Diretório | Descrição | Destaques Técnicos |
| :--- | :--- | :--- |
| `/lista_ordenada_generica` | Lista que mantém ordem automaticamente. | Inserção ordenada e suporte a dados genéricos. |
| `/soma_polinomios_lista` | Soma de polinômios matemáticos. | Cada nó representa um termo ($Ax^n$). |
| `/censo_lista_multi_encadeada` | Lista com ordenação dupla (1990 e 2000). | Nós com múltiplos ponteiros `next` para diferentes critérios de ordenação. |
| `/leitura_arquivo_lista_encadeada` | Importação de dados de alunos. | Leitura de arquivo `.txt` e conversão para nós de lista[cite: 236, 239]. |

### ⏱️ 4. Algoritmos de Ordenação (Sorting)

Análise comparativa entre **Bubble Sort**, **Selection Sort** e **Insertion Sort**.

| Diretório | Descrição | Análise Realizada |
| :--- | :--- | :--- |
| `/ordenacao_basica_simples` | Implementação pura dos algoritmos. | Vetores pequenos para validação lógica[cite: 150]. |
| `/ordenacao_vetor_grande` | Teste de carga com 50.000 elementos. | Comportamento com grandes volumes de dados (aleatórios)[cite: 177]. |
| `/ordenacao_analise_tempo` | Medição de tempo de execução. | Uso da biblioteca `time.h` e `clock()` para medir milissegundos[cite: 196, 201]. |
| `/ordenacao_contagem_custo` | Auditoria de eficiência. | Contagem exata de número de comparações e trocas realizadas[cite: 212, 221]. |

### 🔄 5. Recursividade

| Diretório | Descrição |
| :--- | :--- |
| `/busca_substring_recursiva` | Algoritmo recursivo que busca a ocorrência de uma palavra dentro de um texto, retornando o índice inicial[cite: 251, 256]. |

---

## 🚀 Como Executar

Para compilar os projetos, utilize o **GCC** ou compile diretamente pelo **VS Code**.

**Exemplo 1: Compilando a Agenda (Múltiplos arquivos)**
```bash
cd agenda_tad_modularizada
gcc main.c agenda.c -o sistema_agenda
./sistema_agenda
