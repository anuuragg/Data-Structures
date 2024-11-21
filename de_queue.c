#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1; int rear = -1;

int isFull(){
  return front == (rear+1)%MAX;
}

int isEmpty(){
  return front == -1;
}

void insertFront(int el){
  if(isFull()){
    printf("Queue is Full");
    return;
  } 
  if(isEmpty()){
    front = rear = 0;
  } else if(front == 0){
    front = MAX - 1;
  } else{
    front--;
  }
  queue[front] = el;
  printf("%d inserted from the front\n", el);
}

void insertRear(int el){
  if(isFull()){
    printf("Queue is Full");
    return;
  }
  if(isEmpty()){
    front = rear = 0;
  } else if(rear == MAX - 1){
    rear = 0;
  } else{
    rear++;
  }
  queue[rear] = el;
  printf("%d inserted from the rear\n", el);
}

void deleteFront(){
  if(isEmpty()){
    printf("Queue is empty!");
    return;
  }
  if(front == rear){
    front = rear = -1;
  } else if(front == MAX - 1){
    front = 0;
  } else{
    front++;
  }
}

void deleteRear(){
  if(isEmpty()){
    printf("Queue is empty!");
    return;
  }
  if(front == rear){
    front = rear = -1;
  } else if(rear == 0){
    rear = MAX - 1;
  } else{
    rear--;
  }
}

void display(){
  if(isEmpty()){
    printf("Queue is empty!\n");
    return;
  }
  int i = front;
  printf("Queue Elements: ");
  while(i!=rear){
    printf("%d ", queue[i]);
    i = (i+1)%MAX;
  }
  printf("%d\n", queue[rear]);
}

int main(){
  insertFront(4);
  insertFront(2);
  display();
  insertRear(6);
  insertRear(0);
  display();
  deleteRear();
  display();
  return 0;
}