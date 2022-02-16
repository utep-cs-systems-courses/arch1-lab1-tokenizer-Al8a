#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int space_char(char c)
{
  return c == ' ' || c == '\t' ? 1 : 0; 
}


int non_space_char(char c)
{
  return c != ' ' && c != '\t' && c != '\0' ? 1 : 0;
}


char *word_start(char *str)
{
  /*
    do{
     statements
    }while(expression);

    pointers:
    *ptr++ == *(ptr++)  post-increment pointer address
    *++ptr == *(++ptr)  pre-incremrent pointer address

    ++*ptr      value pre-incremented  
    ++(*ptr)    value pre-incremented
    (*ptr)++    value post-incremented
  */


  /*
  char *ptr = str;
  if(!*ptr){
    return 0;
  }
  while(*ptr){
    if(!space_char(*ptr)){
      return ptr;
    }
    else ++ptr;
  }
  */
  
  do{
    if(non_space_char(*str)){
      return str;
    }   
  }while(*(++str) != '\0'); 
  return 0;
}  



char *word_terminator(char *word)
{
  /*
  char *ptr = word;
  while(!space_char(*ptr) && *ptr != '\0') {
    ++ptr;
  }
  return ptr;
  */
  
  while(1){
    if(!non_space_char(*word))     
      return word;                 
    word++; 
  }
  return 0;
}



int count_words(char *str)
{
  int word_count = 0;
  char in_word = 0;
  char *ptr = str;

  /*
  while(*ptr){
    if(space_char(*ptr)){
      in_word = 0;
      while(space_char(*ptr)){
	++ptr;
      }
    }
    else{
      if(!in_word && non_space_char(*ptr)){
	in_word = 1;
	word_count++;
      }
      ++ptr;
    }
  }
  return word_count;
  */
  
  /*
  while((*(++str) != '\0')){
    if(in_word && space_char(*str)){
      in_word = 0;
    }
    else if(!in_word && non_space_char(*str)){
      in_word = 1;
      word_count++;
    }
  }
  return word_count;
  */

  do{
    if(in_word && space_char(*ptr)){
      in_word = 0;
    }  
    else if(!in_word && non_space_char(*ptr)) {
      in_word = 1;
      word_count++;
    }
  }while(*(++ptr) != '\0');  // pre-incrmement str's address 
  return word_count;  
}


char *copy_str(char *in_str, short len)
{
  char *out_str = (char*) malloc(sizeof(char) * len + 1);

  // error handling 
  if(!out_str){
    fprintf(stderr, "Method: *copy_str\nError: Memory allocation error!"); // stderr = standard error 
    exit(EXIT_FAILURE);                                                    // fprintf(<file>,message)
  }                                                                        // exit(EXIT_FAILURE) == exit(1)

  // temp pointer
  char *c = out_str;  
  short i = 0;

  while(i < len){                              
      *c = *in_str;                 // dereference *in_str into out_str through *c 

      if(*in_str == '\0')
	break;
     
      i++;
      c++;
      in_str++;
  } 
  *c = '\0';                        // clear temp pointer 
  return out_str;
}


char **tokenize(char* str)
{
  int words = count_words(str);
  char **tokens = malloc(sizeof(char*) * (words + 1));  // string + '\0'

  // error handling 
  if(!tokens){
    fprintf(stderr, "Method: tokenize\nError: Memory allocation error!");
    exit(EXIT_FAILURE);
  }

  str = word_start(str);

  for(int i = 0; i < words; ++i){
    char* terminator = word_terminator(str);
    tokens[i] = copy_str(str, terminator - str);
    str = word_start(terminator);
  }

  char **terminator = tokens + words;
  *terminator = 0;
  return tokens;
}


void print_tokens(char **tokens)
{

  char** token = tokens;

  /*
  printf("{\n");
  while(token){
    printf("}\n\n");
    ++token;
  }
  printf("}\n\n");
  */
  
  
  printf("{\n");
  for(char** token = tokens; *token != 0; token++){
    printf("\t%ld) '%s'\n", token - tokens, *token);
  }
  printf("}\n\n");
  
}


void free_tokens(char **tokens)
{
  char **token = tokens;

  /*
  while(*token){
    free(*token);
    ++token;
  }
  free(*token); // free final token 
  free(tokens); // free array of pointers 
  */

  
  while(*token != 0){
    free(*token);
    token++;
  }

  free(*token);
  free(tokens);
}
