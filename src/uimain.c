
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#define BUFFER_SIZE 100



int main()
{
  char user_input[BUFFER_SIZE];
  int choice;

  puts("\nWelcome to Tokenizer!\n");
  while(1){
    fputs("Please select an operation to run:\n\t1. Record and store a new string.\n\t2. Print a past entry.\n\t3 .Display all previous entries.\n\t4. Quit Tokenizer\n", stdout);
    printf("> ");
    fflush(stdout);

    while ((choice = getchar()) == '\n');
    if(choice == EOF)
      goto done;
    
    switch(choice){
    case '1':
      puts("Please enter the new message to be recorded!\n ");
      printf("> ");
      fgets(user_input, BUFFER_SIZE, stdin);
      break;
    case '2':
      puts("Please input a past entry index number.\n");
      break;
    case '3':
      puts("Displaying entry history");
      break;
    case '4':
      puts("Now exiting tokenizer");
      goto done;
    case '\n':
      break;
    default:
      printf("Unrecongized option %c, please try again!\n", choice);
    };

  }  
 done:
  exit(EXIT_SUCCESS);  // exit(0)
}

     
    
   
  
