#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("memory error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d\n", data);
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("stack empty\n");
        return -1;
    }
    int poppedData = (*top)->data;
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("%dis removed\n", poppedData);
    return poppedData;
}

void printStack(struct node *top) {
    if (top == NULL) {
        printf("stack empty\n");
        return;
    }
    printf("print stack\n");
    while (top != NULL) {
        printf("%d \n", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct node *top = NULL; 


    push(&top, 55);
    push(&top, 606);
    push(&top, 808);
    push(&top, 818);
    push(&top, 2.3);
    //printStack(top);

    /*int poppedValue = pop(&top);
    
    if (poppedValue != -1) {
        printf("popped value: %d\n", poppedValue);
    }*/

    printStack(top);

    return 0;
}

