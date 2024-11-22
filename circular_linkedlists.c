#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}node;

void insertAtEnd(node** head, int new_data){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->value = new_data;

  if(*head==NULL){
    *head = new_node;
    new_node->next = new_node;
  } else{
    node* temp = *head;
    while(temp->next!=*head){
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = *head;
  }
}

void deleteFromBeginning(node** head){
  if(*head == NULL){
    printf("List is empty!");
    return;
  } 
  node* temp = *head;
  if(*head == (*head)->next){
    free(*head);
    *head = NULL;
  } else {
    node* last = *head;
    while(last->next!=*head){
      last = last->next;
    }
    *head = (*head)->next;
    last->next = *head;
    free(temp);
  }
}

void traverse(node* head){
  if(head == NULL){
    printf("List is Empty!");
    return;
  }
  node* temp = head;
  do{
    printf("%d -> ", temp->value);
    temp = temp->next;
  } while(temp!=head);
  printf("(head)\n");
}

int main(){
  node* head = NULL;

  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);

  printf("Circular Linked List: ");
  traverse(head);

  deleteFromBeginning(&head);
  printf("After deleting the first node: ");
  traverse(head);
  
  return 0;
}