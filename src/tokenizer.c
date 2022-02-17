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

    
  do{
    if(non_space_char(*str)){
      return str;
    }   
  }while(*(++str) != '\0'); 
  return 0;
  
  /*
  if(*str == '\0'){
    return 0;
  }
  while(space_char(*str)){
      str++;
  }
  return str;
  */
}  



char *word_terminator(char *word)
{
  while(word != 0){
    if(!non_space_char(*word)){     
      return word;
    }
    word++; 
  }
  return 0;
}


int count_words(char *str)
{
  int word_count = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    ++word_count;
  }
  return word_count;
}


char *copy_str(char *in_str, short len)
{
  char *out_str = (char*) malloc(sizeof(char) * (len + 1));

  // error handling 
  if(!out_str){
    fprintf(stderr, "Method: *copy_str\nError: Memory allocation error!"); // stderr = standard error 
    exit(EXIT_FAILURE);                                                    // fprintf(<file>,message)
  }                                                                        // exit(EXIT_FAILURE) == exit(1)

  char *copy = out_str;  

  for(int i = 0; i < len; i++){
    *copy = *in_str;

    if(*copy == '\0'){
      break;
    }
    
    copy++;
    in_str++;
  }
  *copy = '\0';     // set last index to '\0' 
  return out_str;   // return new character array with null character at end appended
}


char **tokenize(char* str)
{
  int word_count = count_words(str);
  char **tokens = malloc(sizeof(char*) * (word_count + 1));

  // error handling 
  if(!tokens){
    fprintf(stderr, "Method: tokenize\nError: Memory allocation error!");
    exit(EXIT_FAILURE);
  }

  str = word_start(str);

  for(int i = 0; i < word_count; ++i){
    char* terminator = word_terminator(str);
    tokens[i] = copy_str(str, terminator - str);    
    str = word_start(terminator);
  }

  char **terminator = tokens + word_count;  // tokens[word_count-1] available indices          points out of bounds
  *terminator = 0;                          // set zero pointer
  return tokens;
}


void print_tokens(char **tokens)
{
  int count = 0;
  while(*tokens != 0){
    printf("[%d]\t\'%s\'\n",count, *tokens);
    count++;
    tokens++;   
  }
}


void free_tokens(char **tokens)
{
  char **token = tokens;
 
  while(*token != 0){
    free(*token);
    token++;
  }

  free(*token);
  free(tokens);
}
