#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List *list = (List*) calloc(1, sizeof(List));

  if(!list){
    fprintf(stderr,"Method: init_history\nError: Memory allocation error!");
    exit(EXIT_FAILURE);
  }
  return list;
}


int str_len(char *str)
{
  char *ptr = str;
  while(*ptr != '\0'){
    ptr++;
  }
  return ptr - str;
}



void add_history(List *list, char *str)
{
  Item *new_item = (Item*) malloc(sizeof(Item));
  Item *current_item = list->root;
  int index;  
  int str_length =  str_len(str);

  new_item -> str = copy_str(str, str_length);

  if(!new_item){
    fprintf(stderr,"Method: add_history\nError: Memory allocation error!");
   exit(EXIT_FAILURE);
  }
  
  // if history is empty set new_item to root 
  if(current_item == NULL){
    list->root = new_item;
    new_item->id = 1;
  }
  
  else{
        
    while(current_item->next != NULL){
      current_item = current_item->next;
      index++;
    }
    current_item->next = new_item;
    new_item->id = current_item->id + 1;
  }
}

void reverse_history(List *list){

  Item *current_item = list->root;
  Item *previous_item = 0;
  Item *next_item = 0;

  while(current_item != NULL){
    
    next_item = current_item->next; // store next
    current_item->next = previous_item; // reverse current_item's pointer

    // iterate once ahead 
    previous_item = current_item;
    current_item = next_item;
  }
  list->root = previous_item; 
}


char *get_history(List *list, int id)
{
  Item *current_item= list->root;
  while(current_item){
    if(current_item->id == id){
      return current_item->str;
    }
    current_item = current_item->next;
  }
}



void print_history(List *list)
{
  Item *current_item = list->root;
  int counter = 0;
  while(current_item){

    counter++;
    
    if(current_item->id == 1){
      printf("[%d] - %s", counter, current_item->str);
    }
    else{
    printf("[%d] - %s", counter, current_item->str);
    }
    current_item = current_item->next;
  }
}

void free_history(List *list)
{
  Item *current_item = list->root;
  Item *prev_item;

  while(current_item){
    prev_item = current_item;
    current_item = current_item->next;

    free(prev_item->str);    // free string
    free(prev_item);         // free node
  }
  free(list);                // free linked-list
} 

