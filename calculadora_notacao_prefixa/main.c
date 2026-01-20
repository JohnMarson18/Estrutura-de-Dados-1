#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

#define MAX_QUEUE_SIZE 100

typedef struct {
    char items[MAX_QUEUE_SIZE][10]; 
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, char *item) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        fprintf(stderr, "Erro: fila cheia\n");
        exit(EXIT_FAILURE);
    }
    q->rear++;
    strcpy(q->items[q->rear], item); 
}

char *dequeue(Queue *q) {
    if (q->front > q->rear) {
        fprintf(stderr, "Erro: fila vazia\n");
        exit(EXIT_FAILURE);
    }
    char *item = q->items[q->front];
    q->front++;
    return item;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int eval_prefix_expression(Queue *expr) {
    char token[10];
    strcpy(token, dequeue(expr));

    if (isdigit(token[0])) {
        return atoi(token);  
    } else {

        int operand1 = eval_prefix_expression(expr);
        int operand2 = eval_prefix_expression(expr);

        switch (token[0]) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            default:
                printf("Operador inválido: %c\n", token[0]);
                exit(EXIT_FAILURE);
        }
    }
}

int main() {
    Queue expr_queue;
    initQueue(&expr_queue);

    char expr[][10] = {"-", "+", "*", "9", "+", "2", "8", "*", "+", "4", "8", "6", "3"};
    int num_elements = sizeof(expr) / sizeof(expr[0]);
    for (int i = 0; i < num_elements; ++i) {
        enqueue(&expr_queue, expr[i]);
    }

    int result = eval_prefix_expression(&expr_queue);

    printf("Resultado da expressão: %d\n", result);
    system("pause");
    return 0;
}
