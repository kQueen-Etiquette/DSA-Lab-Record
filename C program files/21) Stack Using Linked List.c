#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * next;
}node;

node * PUSH(node * head, int SIZE, int value);
void DISPLAY(node * head);
node * POP(node * head);
void PEEK(node * head);

int main(void) {
  int SIZE, value, choice;
  printf("Enter the size of STACK: ");
  scanf("%d", &SIZE);
  node * STACK = NULL;
  while(1) {
    printf("\nChoose the following: \n");
    printf("1. Push \n2. Pop \n3. Display \n4. Peek \n5. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1: printf("Enter an element to push: ");
              scanf("%d", &value);
              STACK = PUSH(STACK, SIZE, value);
              break;
      case 2: STACK = POP(STACK);
              break;
      case 3: DISPLAY(STACK);
              break;
      case 4: PEEK(STACK);
              break;
      case 5: exit(0);
              break;
      default: printf("\nIncorrect option choosen!!!\n");
              break;
    }
  }
}

node * PUSH(node * head, int SIZE, int value) {
  node * temp = NULL;
  node * tail = NULL;
  temp = (node *)malloc(sizeof(node));
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    printf("\nINSERTION SUCCESS!!!\n");
  }
  else {
    tail = head;
    int count = 1;
    while(tail->next != NULL) {
      tail = tail->next;
      count++;
      }
    if (count == SIZE) {
        printf("\nSTACK OVERFLOW!!!\n");
    }
    else{
      tail->next = temp;
      printf("\nINSERTION SUCCESS!!!\n");
    }
  }
  return head;
}

void DISPLAY(node * head) {
  node * tail = head;
  printf("\n");
  if (head == NULL) printf("STACK EMPTY!!!");
  while(tail != NULL) {
    printf("-> %d ", tail->data);
    tail = tail->next;
  }
  printf("\n");
}

node * POP(node * head) {
  node * tail = head;
  node * pop = head;
  if(tail == NULL) {
    printf("\nSTACK IS EMPTY!!!\n");
  }
  else{
    int count = 0;
    while(tail->next != NULL) {
      count++;
      pop = tail;
      tail = tail->next;
    }
    printf("\nPOPPED ELEMENT = %d\n", tail->data);
    pop->next = NULL;
    if (count == 0) head = NULL;
  }
  return head;
}

void PEEK(node * head) {
  node * tail = head;
  if(tail == NULL) {
    printf("\nSTACK IS EMPTY!!!\n");
  }
  else{
    while(tail->next != NULL) {
      tail = tail->next;
    }
    printf("\nPEEK ELEMENT = %d\n", tail->data);
  }
}