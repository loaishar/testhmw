#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph

// Data structure to store a graph object
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

// Function to create an adjacency list from specified edges
struct Graph *createGraph(struct Edge edges[], size_t nodes)
{
  // allocate storage for the graph data structure
  struct Graph *graph = malloc(sizeof *graph + sizeof(struct Node *[nodes]));
  if (graph)
    graph->nodes = nodes;
  // initialize head pointer for all vertices
  for (int i = 0; i < nodes; i++)
  {
    graph->head[i] = NULL;
  }

  // add edges to the directed graph one by one
  for (int i = 0; i < nodes; i++)
  {
    // get the source and destination vertex
    int src = edges[i].src;
    int dest = edges[i].dest;
    int weight = edges[i].weight;

    // allocate a new node of adjacency list from src to dest
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;

    // point new node to the current head
    newNode->next = graph->head[src];

    // point head pointer to the new node
    graph->head[src] = newNode;
  }

  return graph;
}

// Function to print adjacency list representation of a graph
void printGraph(struct Graph *graph, size_t nodes)
{
  for (int i = 0; i < nodes; i++)
  {
    // print current vertex and all its neighbors
    struct Node *ptr = graph->head[i];
    while (ptr != NULL)
    {
      printf("%d —> %d (%d)\t", i, ptr->dest, ptr->weight);
      ptr = ptr->next;
    }

    printf("\n");
  }
}

// Weighted Directed graph implementation in C

bool Graph_expand(struct Graph **g, size_t nodes)
{
  if (*g && (*g)->nodes < nodes)
  {
    struct Graph *ng = realloc(*g, sizeof *ng + sizeof(struct Node *[nodes]));
    if (ng)
    {
      *g = ng;
      (*g)->nodes = nodes;
      return true;
    }
  }
  return false;
}

int main()
{
  char user_input;
  while (scanf("%c", &user_input))
  {
    if (user_input == 'A')
    {
      printf("please, start buting your input: \n");
      char inputString[1000], inputString2[1000], c;
      int index = 0;
      /* Read string from user using getchar
       inside while loop */

      while ((c = getchar()) != '\n')
      {
        inputString[index] = c;
        index++;
      }

      inputString[index] = '\0';
      strcpy(inputString2, inputString);
      /* Print string stored in inputString using putchar */
      char delim[] = "n";

      char *ptr = strtok(inputString, delim);
      int len = 0;
      while (ptr != NULL)
      {
        if (ptr[0] != 'A')
        {
          printf("'%s'\n", ptr);
          len = len + (strlen(ptr) - 1) / 2;
          printf("\n%d\n", len);
        }
        ptr = strtok(NULL, delim);
      }
      printf("----------------------------------------------------------------------\n");

      struct Edge *edges = (struct Edge *)malloc(len * sizeof(struct Edge));
      int src_point, j = 0;
      for (int i = 0; i < strlen(inputString2); i++)
      {
        if (inputString2[i] == 'n')
        {
          src_point = ++i;
          while ((inputString2[i + 1] != 'n') && (inputString2[i + 1] != '\0'))
          {
            edges[j].src = inputString2[src_point] - '0';
            edges[j].dest = inputString2[++i] - '0';
            edges[j].weight = inputString2[++i] - '0';
            j++;
          }
        }
      }
      struct Graph *graph;
      graph = createGraph(edges, len);
      printGraph(graph, len);
      if (Graph_expand(&graph, len))
        puts("Expansion succeeded");
      printf("%zu\n", graph->nodes);

      // Function to print adjacency list representation of a graph
    }
    if (user_input == 'B')
        {






        }
  }
  return 0;
}