#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"
void addEdge(struct Node **node_pp, int dest, int weight)
{
 // struct Node *node = *node_pp;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->dest = dest;
  newNode->weight = weight;

  // point new node to the current head
  newNode->next = *node_pp;

  // point head pointer to the new node
  *node_pp = newNode;
}