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



void add_history(List *list, char *str)
{
  
  int len;
  Item *current_item = list->root;
  Item *new_item = (Item*) malloc(sizeof(Item));
  new_item->next = 0; 

  if(!new_item){
    fprintf(stderr,"Method: init_history\nError: Memory allocation error!");
    exit(EXIT_FAILURE);
  }

  len = 0;
  while(*str != '\0'){
    ++len;
    ++str;
  }

  if(current_item == 0){
    list->root = new_item;
    new_item->id = 0;
  }
  else{
    while(current_item->next != 0){
      current_item =  current_item->next;
    }
    current_item->next = new_item;
    new_item->id = current_item->id + 1;
  }

  str = str-len;
  char *copied_string =(char*) malloc(sizeof(char));
  copied_string= copy_str(str,len);
  new_item->str = copied_string;
}



char *get_history(List *list, int id)
{
  Item* item= list->root;
  while(item){
    if(item -> id == id){
      return item->str;
    }
    item = item->next;
  }
}



void print_history(List *list)
{
  Item* item = list->root;
  while(item){
    printf("[%d]\t's'\n", item->id, item->str);
    item = item->next;
  }
}



void free_history(List *list)
{
  Item *item = list->root;
  Item *prev_item;

  while(item){
    prev_item = item;
    item = item->next;

    free(prev_item->str);    // free string
    free(prev_item);         // free node
  }
  free(list);                // free linked-list
} 

