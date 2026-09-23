#include <stdio.h> // This is preprocessor directives, these are of 4 types 
                   // 1- File inclusion, 2- Macro Substitution, 3- Conditional Compilation
                   // 4- Compiler Control(like #pragma and #error)
#include "add_del_update_print.h"

int main(int argc, char **argv) {
  NODE *head = NULL;

  insertAtHead(&head, 2);
  insertAtTail(&head, 5);
  insertAtTail(&head, 3);
  //insertAfterNode(struct Node* prev_node, int new_data);
  
  deleteNodeByKey(&head, 5);
  deleteNodeAtPosition(&head, 9);
  
  printList(head);
}
