// List Sort
#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head, *tail = NULL;

void addNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) { // 리스트가 비었을 경우
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void ListSort(int ary[], int count) {
    Node *current = head, *index = NULL;
    int temp;
    
    for (int i = 0; i < count; i++) {
        addNode(ary[i]);
    }
    
    if (head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void display() {
    Node *current = head;
    if (head == NULL) {
        printf("리스트가 비었습니다. \n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main() {
    int data[N] = {69, 10, 30, 2, 16, 8, 31, 22};
    int temp;

    printf("정렬 전 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 버블 정렬 알고리즘
    ListSort(data, N);

    printf("정렬 후 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    display();
}