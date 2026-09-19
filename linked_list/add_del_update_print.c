// Library to add, del, update, print
typedef struct linked_list NODE;
struct linked_list {
    int data;
    NODE *next;
};

int add_to_head(NODE *head, int data) {
  NODE *new_node = (NODE *)malloc(sizeof(NODE));
  if(new_node == NULL) {
    printf("Mem LOW\n");
    return -1;
  }
  
  new_node->data = data;

  // Add to empty list.
  if(head == NULL) {
    new_node->next = NULL;
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }

  return 0;
}
