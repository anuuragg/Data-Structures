#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(){
  if (front == 0 && rear >= MAX){
    printf("\nQueue is full\n");
  } else{
    rear++;
    printf("\nEnter an element to add: ");
    scanf("%d", &queue[rear]);
  }
}

void dequeue(){
  if (front == -1 && rear == -1){
    printf("\nQueue is empty\n");
  } else{
    for(int i=0; i<rear; i++){
      queue[i] = queue[i+1];
    }
    rear--;
    if(rear == -1){
      front = -1;
    }
  }
}

void display(){
  if(front == -1 && rear == -1){
    printf("\nQueue is empty\n");
  } else{
    for(int i=0; i<=rear; i++){
      printf("%d ", queue[i]);
    }
  }
}

int main(){
  while(1){
    int choice;
    printf("\nPlease enter: \n1 -> enqueue\n2 -> dequeue\n3 -> display\nchoice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      default:
        printf("\nInvalid Choice!\n");
    }
  }
  return 0;
}