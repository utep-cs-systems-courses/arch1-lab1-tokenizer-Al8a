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
  char *ptr  = str;
  while(ptr != "\0"){
    ptr++;
  }
  return ptr-str;
}



void add_history(List *list, char *str)
{
  Item *new_item = (Item*) malloc(sizeof(Item));
  Item *item = list->root;
  Item *previous_item;
  int index;
  
  
  int str_length = str_len(*str);
  new_item -> str = copy_str(str, str_length);
  
  // if history is empty set new_item to head node 
  if(!item){
    list->root = new_item;
    new_item->id = 1;
  }
  
  else{

    index = 0;    

    while(item){
      previous_item = item;
      item = item->next;
      index++;
    }
    
    previous_item->next = new_item;
    new_item->id = index + 1;
  }
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

  while(current_item){
    printf("[%d] - %s\n", current_item->id, current_item->str);
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

