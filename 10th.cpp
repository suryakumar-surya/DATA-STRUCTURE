#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void delete(int val) {
    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) head = head->next;
    else prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10); insert(20); insert(30);
    display();           // 30 -> 20 -> 10 -> NULL
    delete(20);
    display();           // 30 -> 10 -> NULL
    return 0;
}

