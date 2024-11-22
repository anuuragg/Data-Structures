#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node* prev;
  struct node* next;
}node;

void insertAtBeginning(node** head, int new_data){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->value = new_data;

  new_node->next = *head;
  new_node->prev = NULL;

  if(*head!=NULL){
    (*head)->prev = new_node;
  }

  *head = new_node;
}

void insertAtEnd(node** head, int new_data){
  node* new_node = (node*)malloc(sizeof(node));
  new_node->value = new_data;
  new_node->prev = NULL;

  if(*head == NULL){
    new_node->prev = NULL;
    *head = new_node;
    return;
  }

  node* temp = *head;
  while(temp->next!=NULL){
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

node* findNode(node* head, int key){
  node* temp = head;
  while(temp!=NULL){
    if(temp->value == key){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void deleteNode(node** head, node* del){
  if(*head == NULL || del == NULL){
    return;
  }

  if(del->next!=NULL){
    del->next->prev = del->prev;
  }

  if(del->prev!=NULL){
    del->prev->next = del->next;
  } else{
    *head = del->next;
  }

  free(del);
}

void traverse(node* head){
  node* temp = head;
  while(temp!=NULL){
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

void traverseBackward(node* head){
  node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  while(temp!=NULL){
    printf("%d ", temp->value);
    temp = temp->prev;
  }
  printf("\n");
}

int main(){
  node* head = NULL;
  insertAtBeginning(&head, 4);
  insertAtBeginning(&head, 6);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 8);
  traverse(head);
  traverseBackward(head);
  node* del = findNode(head, 8);
  deleteNode(&head, del);
  traverse(head);
  return 0;
}