typedef struct __node {
  int value;
  struct __node *next;
} node_t;

void quicksort(node_t **list, node_t *end_node);