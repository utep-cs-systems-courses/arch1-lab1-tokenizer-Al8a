#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history();

/* Returns the length of a given string */
int str_len(char *str);

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str);

/* Reverse the contents of the linked-list to allow for proper
   indexing when the user requests an element.
*/
void reverse_history(List *list);

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find 
*/
char *get_history(List *list, int id);

/* Print the entire contents of the list. */
void print_history(List *list);

/* Free the history list and the strings it references. */
void free_history(List *list);


#endif
