#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* next;
}node;

void insertAtBeginning(node** head, int new_data){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->value = new_data;
  new_node->next = *head;
  *head = new_node;
}

void printList(node* head){
  node* temp = head;
  while(temp!=NULL){
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}

void deleteAtBeginning(node** head){
  if(*head==NULL) return;
  node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

int main(){
  node* head = NULL;

  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 30);
  
  printf("Linked List: ");
  printList(head);

  deleteAtBeginning(&head);
  printf("After deleting the first node: ");
  printList(head);

  insertAtBeginning(&head, 60);
  printList(head);
  
  return 0;
}