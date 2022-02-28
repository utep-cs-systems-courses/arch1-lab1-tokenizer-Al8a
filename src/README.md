Project 1: Tokenizer
====================
# Description
This program's code build a linked-list called history that allows user input to be taken and stored to later be broken up into tokens and displayed.

# Anticipated learning outcomes
Build expirence and familiarity with pointers, and also to achieve and demonstrate competencies related to 
- Use of program command-line driver development tools including an edtior, c compiler, make, and git.
- Concepts described in chapters 5-7 of Kernigham & Ritchie's "C Programming Language" such as
  - Declaration and use of pointers.
  - Ability to initialize and use structs.
  - Take and store user input using macros and character arrays.
  -  Grasp of pointer arithmetic  

# Files 
The following are source files for Tokenizer (Lab 1).

 - uimain.c:  Main file with the UI to interact with the user. Given the user's input, it is either used as a means of builidng a linked-list based on given inputs or as a means of recalling past entries.
 - tokenizer.h: Header file containing all the declarations and relevant methods to be used to determine how to tokenize a string given by the user.
 - tokenizer.c: Defines functions to tokenize user inputted strings.
 - history.h: Header file containig all the declarations and relevanmt methods to be used to store an user input and to later tokenize it in a linked-list. 
 - histroy.c: Defines function to createand utilize a linked-list containing user inputted strings.

You can compile this program using the command

    $ cc  -g -O3 -o tokenizer uimain.c tokenizer.c history.c 
    or
    $ make
   
The following command runs the program

    $ ./tokenizer
    or
    $ make run 


