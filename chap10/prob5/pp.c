#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("queue is empty\n");
        return -1; 
    }
    int deletedData = (*head)->data;
    struct node *temp = *head;
    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    free(temp);
    printf("%d is removed\n", deletedData);
    return deletedData;
}

void printQueue(struct node *head) {
    printf("print Queue\n");
    if (head == NULL) {
        printf("queue is empty ;\n");
        return;
    }
    while (head != NULL) {
        printf("%d \n", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL; 
    struct node *tail = NULL;

    addq(&head, &tail, 200);
    addq(&head, &tail, 455);
    addq(&head, &tail, 103);
    addq(&head, &tail, 456);
    addq(&head, &tail, 1);

    printQueue(head);
    
   /*int deletedValue = delete(&head, &tail);
    if (deletedValue != -1) {
        printf("deletedvalue: %d\n", deletedValue);
    }*/
    printQueue(head);

    return 0;
}

