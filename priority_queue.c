#include <stdio.h>
#define MAX 100

typedef struct{
  int value;
  int priority;
}p_queue;

p_queue queue[MAX];
int size = 0;

void enqueue(int value, int priority){
  if(size == MAX){
    printf("Queue is Full!");
    return;
  } else{
    queue[size].value = value;
    queue[size].priority = priority;
    size++;
  }
}

int dequeue(){
  if(size == 0){
    printf("Queue is Empty!");
    return 1;
  }  
  int hp = queue[0].priority;
  int pos = 0;
  for(int i=pos;i < size; i++){
    if(queue[i].priority > hp){
      hp = queue[i].priority;
      pos = i;
    }
  }
  int dequeued_value = queue[pos].value;
  for(int i = pos;i < size; i++){
    queue[i] = queue[i+1];
  }
  size--;
  return dequeued_value;
}

void display(){
  if(size == 0){
    printf("Queue is Empty!");
  } else{
    for(int i=0; i<size; i++){
      printf("Value: %d, Priority: %d\n", queue[i].value, queue[i].priority);
    }
  }
}

int main(){
  enqueue(10, 3);
  enqueue(20, 2);
  enqueue(30, 5);
  enqueue(40, 1);
  display();
  printf("Dequeued: %d\n", dequeue());
  printf("Dequeued: %d\n", dequeue());
  display();
  return 0;
}