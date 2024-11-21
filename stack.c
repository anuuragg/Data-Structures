#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(){
  if(top >= MAX-1){
    printf("StackOverflow :(");
  } else {
    top++;
    printf("\nenter an element to push into the stack: ");
    scanf("%d", &stack[top]);
    printf("\nPushed %d into the stack\n", stack[top]);
  }
}

void pop(){
  if(top < 0){
    printf("StackUnderflow :(");
  } else {
    printf("\nPopped %d from the stack\n", stack[top]);
    top--;
  }
}

void display(){
  if(top < 0){
    printf("\nStack is empty :/");
  } else {
    for(int i=top; i >= 0; i--){
      printf("%d ", stack[i]);
    }
  }
}

int main(){
  while(1){
    int choice;
    printf("\nPlease enter: \n1 -> push\n2 -> pop\n3 -> display\nchoice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        push();
        break;
      case 2:
        pop();
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