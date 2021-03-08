#include "quick_sort.h"
#include <stdbool.h>
#include <stdio.h>
#define MAX_LEVEL 1000

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

static inline void list_add_node_t(node_t **list, node_t *node_t) {
  node_t->next = *list;
  *list = node_t;
}

static inline void list_concat(node_t **left, node_t *right) {
  while (*left)
    left = &((*left)->next);
  *left = right;
}

void quicksort(node_t **list, node_t *end_node) {
  if (!*list)
    return;

  node_t *beg[MAX_LEVEL], *end[MAX_LEVEL];
  node_t *result = NULL;
  beg[0] = *list;
  end[0] = end_node;

  int i = 0;

  while (i >= 0) {
    node_t *L = beg[i];
    node_t *R = end[i];

    if (L != R) {

      node_t *pivot = L;
      int value = pivot->value;
      node_t *p = pivot->next;
      pivot->next = NULL;

      node_t *left = NULL, *right = NULL;
      node_t *l_tail = NULL, *r_tail = NULL;
      while (p) {
        node_t *n = p;
        p = p->next;
        if (n->value > value && r_tail == NULL) {
          r_tail = n;
        }
        if (n->value <= value && l_tail == NULL) {
          l_tail = n;
        }
        list_add_node_t(n->value > value ? &right : &left, n);
      }
      beg[i] = left;
      end[i] = l_tail;
      beg[i + 1] = pivot;
      end[i + 1] = pivot;
      beg[i + 2] = right;
      end[i + 2] = r_tail;

      i += 2;
    } else {
      if (L) {
        list_add_node_t(&result, L);
      }
      i--;
    }
  }
  *list = result;
}