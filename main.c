#include "quick_sort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool list_is_ordered(node_t *list) {
  bool first = true;
  int value;
  while (list) {
    if (first) {
      value = list->value;
      first = false;
    } else {
      if (list->value < value)
        return false;
      value = list->value;
    }
    list = list->next;
  }
  return true;
}

static void list_display(node_t *list) {
  printf("%s IN ORDER : ", list_is_ordered(list) ? "   " : "NOT");
  while (list) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("\n");
}

static node_t *list_make_node_t(node_t *list, long value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (!new_node) {
    return list;
  }
  new_node->value = value;
  new_node->next = list;
  return new_node;
}

static void list_free(node_t **list) {

  node_t *curr = *list;
  node_t *tmp;

  while (curr) {
    tmp = curr->next;
    free(curr);
    curr = tmp;
  }

  *list = NULL;
}

int main(int argc, char **argv) {
  size_t count = 20;

  node_t *list = NULL;
  while (count--)
    list = list_make_node_t(list, random() % 1024);

  node_t *end_node = list;
  while (end_node->next && end_node) {
    end_node = end_node->next;
  }

  list_display(list);
  quicksort(&list, end_node);
  list_display(list);

  if (!list_is_ordered(list))
    return EXIT_FAILURE;

  list_free(&list);
  return EXIT_SUCCESS;
}