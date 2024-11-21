#include <stdio.h>
#define MAX 100

int queue[MAX];
int rear = -1; int front = -1;

int isFull(){
  return (rear+1) % MAX == front;
}

int isEmpty(){
  return front == -1;
}

void enqueue(){
  if(isFull()){
    printf("Queue is full");
    return;
  } 
  if(front == -1){
    front = 0;
  }
  rear = (rear+1)%MAX;
  printf("Enter an element to add: ");
  scanf("%d", &queue[rear]);
}

int dequeue(){
  if(isEmpty()){
    printf("Queue is empty");
    return -1;
  }
  if(front == rear){
    front = rear = -1; 
  } else {
    front = (front+1)%MAX;
  }
}

void display(){
  if(isEmpty()){
    printf("Queue is empty");
    return;
  }
  int i = front;
  while(1){
    printf("%d ", queue[i]);
    if(i==rear){
      break;
    }
    i = (i+1)%MAX;
  }
  printf("\n");
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