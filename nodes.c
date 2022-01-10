#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"
 int Node_delete(struct Graph *graph, int distance)
{
  int res = 0;
  for (int i = 0; i < graph->nodes; i++)
  {
    struct Node *first = graph->head[i];
    struct Node *n = first;
    while (first && first->dest == distance)
    {
      first = first->next;
      free(n);
      res++;
      n = first;
    }
    while (n && n->next)
    {
      struct Node *next = n->next;
      if (next->dest == distance)
      {
        n->next = next->next;
        free(next);
        res++;
      }
      n = n->next;
    }
    graph->head[i] = first;
  }
  return res;
}

void Node_delete_list(struct Node **node_pp)
{
  struct Node *node = *node_pp;
  while (node)
  {
    struct Node *next = node->next;
    free(node);
    node = next;
  }

  *node_pp = NULL;
}