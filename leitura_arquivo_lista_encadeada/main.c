#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar a ID do estudante e o coeficiente de rendimento CR
typedef struct {
    int id;
    float cr;
} StudentData;

// Estrutura para representar um nó da lista
typedef struct Node {
    StudentData* dataPtr;
    struct Node* link;
} NODE;

// Função para criar um novo nó
NODE* createNode(StudentData* data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->dataPtr = data;
    newNode->link = NULL;
    return newNode;
}

// Function to read students from a file
NODE* readStudentsFromFile(const char* filename, int* numStudents) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Erro: NAO FOI POSSIVEL ABRIR %s\n", filename);
        return NULL;
    }

    NODE* head = NULL;
    NODE* last = NULL;
    int count = 0;

    while (count < 10) {
        StudentData* student = (StudentData*)malloc(sizeof(StudentData));
        if (fscanf(file, "%d %f", &student->id, &student->cr) != 2) {
            free(student);
            break;
        }

        NODE* newNode = createNode(student);
        if (!head) {
            head = newNode;
        } else {
            last->link = newNode;
        }
        last = newNode;
        count++;
    }

    fclose(file);
    *numStudents = count;
    return head;
}

// Function to print the list
void printStudentList(NODE* node) {
    while (node) {
        printf(" ID = %2d, CR = %.2f\n", node->dataPtr->id, node->dataPtr->cr);
        node = node->link;
    }
}

int main(void) {
    int numStudents;
    NODE* studentList = readStudentsFromFile("students.txt", &numStudents);

    if (studentList) {
        printStudentList(studentList);
    }
    system("pause");
    return 0;
}