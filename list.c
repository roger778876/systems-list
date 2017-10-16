#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node *next;
};

void print_list(struct node *node){
  while (node){
    printf("%d\n", node -> i);
    node = node -> next;
  }
}

struct node *insert_front(struct node *node, int i){
  struct node *front = (struct node *) malloc(sizeof(struct node));
  front -> i = i;
  front -> next = node;
  return front;
}

struct node *free_list(struct node *node){
  struct node *first = node;
  struct node *next;
  while (node){
    next = node -> next;
    free(node);
    node = next;
  }
  return NULL; 
}

void main(){
  struct node *list = NULL;
  print_list(list);

  list = insert_front(list, 1);
  print_list(list);

  list = insert_front(list, 2);
  print_list(list);

  list = free_list(list);
  print_list(list);
}