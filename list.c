// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;

  return mylist;
}

void list_free(list_t *l) {
  free(l);
  list_t* mylist = (list_t *) malloc(sizeof(list_t));
  mylist->head = NULL;
  l = mylist;
}

void list_print(list_t *l) {
  node_t* curr = l->head;
  while (curr != NULL) {
    printf("%d\n", curr->value);
    curr = curr->next;
  }
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { //tested
  node_t* curr = l->head;
  int length = 0;
  while (curr != NULL) {
    length++;
    curr = curr->next;
  }
  return length; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t* curr = l->head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = (node_t *) malloc(sizeof(node_t));
  curr->next->value = value;
  curr->next->next = NULL; 
}

void list_add_to_front(list_t *l, elem value)  { //tested
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  if (l->head!=NULL){
    new_node->next = l->head;
    l->head = new_node;
  }
  else{
    l->head = new_node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (index <= 0) {
    list_add_to_front(l, value);
  } else if (index == list_length(l) - 1) {
    list_add_to_back(l, value);
  }
  node_t* curr = l->head;
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  node_t* temp;
  new_node->value = value;
  while (index > 0) {
    curr = curr->next;
    index--;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

elem list_remove_from_back(list_t *l) {
  node_t* curr = l->head;
  if (curr->next == NULL) {
    free(curr);
  }
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  free(curr->next);
  curr->next = NULL;
}
elem list_remove_from_front(list_t *l) { return -1; }
elem list_remove_at_index(list_t *l, int index) { return -1; }

bool list_is_in(list_t *l, elem value) { return false; }
elem list_get_elem_at(list_t *l, int index) {
    int curr_index = 0;
    node_t* curr = l->head;
    while (curr != NULL) {
      if (curr_index == index) {
        return curr->value;
      }
    curr = curr->next;
    curr_index++;
    }
}
int list_get_index_of(list_t *l, elem value) { 
  node_t* curr = l->head;
  int curr_index = 0;
  while (curr != NULL) {
    if (curr->value == value) {
      return curr_index;
    }
    curr = curr->next;
    curr_index++;
  }
  return curr_index;
}

