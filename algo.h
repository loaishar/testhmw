#ifndef _algo_H_
#define _algo_H_


// a constant definition exported by library:
#define INFINITY 999

// a function prototype for a function exported by library:

struct Graph
{
  // An array of pointers to Node to represent an adjacency list
  size_t nodes;
  struct Node *head[];
};

// Data structure to store adjacency list nodes of the graph
struct Node
{
  int dest, weight;
  struct Node *next;
};

// Data structure to store a graph edge
struct Edge
{
  int src, dest, weight;
};
void addEdge(struct Node **node_pp, int dest, int weight);
 int Node_delete(struct Graph *graph, int distance);
void Node_delete_list(struct Node **node_pp);




#endif