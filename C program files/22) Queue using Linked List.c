#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data; 
    struct element * next;
}element;

element *front = NULL, *rear = NULL;

void enQueue(int value);
void Display();
void deQueue();
void Peek();

void main() {
  int choice, value;
  element * Queue = NULL;
  while(1) {
    printf("\n1. enQueue \n2. deQueue \n3. Display \n4. Peek \n5. Exit \n");
    printf("Select an option: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("Enter a value: ");
            scanf("%d", &value);
            enQueue(value);
            break;
      case 2: deQueue();
            break;
      case 3: Display(Queue);
            break;
      case 4: Peek();
            break;
      case 5: exit(0);
      default: printf("\nInvalid choice of option!!!\n");
            break;
    } 
  } 
}

void enQueue(int value) {
    element * NewElement = (element *)malloc(sizeof(element));
    NewElement->data =  value;
    NewElement->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = NewElement;
    }
    else {
        rear->next = NewElement;
        rear = NewElement;
    }
    printf("\nInsertion Successfull\n");
}

void Display() {
    if (front == rear) {
        printf("\nQueue is empty\n");
    }
    else {
        element * temp = front;
        while(temp) {
            printf("-> %d  ", temp->data);
	        temp = temp -> next;
        }
    }
}

void deQueue() {
    if (front == rear) {
        printf("\nQueue is empty\n");
    }
    else {
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        printf("\ndeQueue successfull\n");
    }
}

void Peek() {
    if (front == rear) {
        printf("\nQueue is empty\n");
    }
    else {
        while(rear->next != NULL) {
        rear = rear->next;
        }
        printf("\nPeek element = %d\n", rear->data);
    }
}