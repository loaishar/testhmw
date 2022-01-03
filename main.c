#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INFINITY 999

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
/*******************************/
int Dijkstra(int **Graph, int n, int i_input, int j_input)
{
 // int xer;
  //scanf(" %d", &xer);
  //int *arr22 =(int*) malloc(xer * sizeof(int));
  int *distance =(int*) malloc(n * sizeof(int)); // pred[V];
  /****/

  
/****/
int **cost;
      /* allocate the array */
      cost = malloc(n * sizeof *cost);
      for (int i = 0; i < n; i++)
      {
        cost[i] = malloc(n * sizeof *cost[i]);
      }

/****/



  int *visited = (int *)malloc(n * sizeof(int)), count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++)
  {
    distance[i] = cost[i_input][i];
    // pred[i] = i_input;
    visited[i] = 0;
  }

  distance[i_input] = 0;
  visited[i_input] = 1;
  count = 1;

  while (count < n - 1)
  {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          // pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
  {
    if (i != i_input)
    {
      if (i == j_input)
      {
        return distance[i];
      }
    }
  }
  return -1;
}
/*******************************/

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
// int Node_delete(struct Graph *graph,int dest) {
/*
void deleteNode(struct Node **head_ref, int key)
{
struct Node *temp = *head_ref, *prev;

if (temp != NULL && temp->dest == key)
{
  *head_ref = temp->next;
  free(temp);
  return;
}
// Find the key to be deleted
while (temp != NULL && temp->dest != key)
{
  prev = temp;
  temp = temp->next;
}

// If the key is not present
if (temp == NULL)
  return;

// Remove the node
prev->next = temp->next;

free(temp);
}
*/
//}
static int Node_delete(struct Graph *graph, int distance)
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

void addEdge(struct Node **node_pp, int dest, int weight)
{
  struct Node *node = *node_pp;
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->dest = dest;
  newNode->weight = weight;

  // point new node to the current head
  newNode->next = *node_pp;

  // point head pointer to the new node
  *node_pp = newNode;
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

int main()
{
  char *inputString2;
  int len;
  struct Graph *graph;
  char user_input;
  while (scanf("%c", &user_input))
  {
    if (user_input == 'A')
    {
      printf("please, start buting your input: \n");
      char *inputString = malloc(1), c;
      int index = 0;
      /* Read string from user using getchar
       inside while loop */

      while ((c = getchar()) != '\n')
      {
        inputString[index] = c;
        inputString = realloc(inputString, index + 1);
        index++;
      }

      inputString[index] = '\0';

      inputString2 = malloc(sizeof(char) * index);
      strcpy(inputString2, inputString);
      /* Print string stored in inputString using putchar */
      char delim[] = "n";

      char *ptr = strtok(inputString, delim);
      len = 0;
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

      graph = createGraph(edges, len);
      printGraph(graph, len);

      // Function to print adjacency list representation of a graph
    }
    if (user_input == 'B')
    {
      char *s = malloc(1);
      int c;
      int i = 0;
      /* Read characters until found an EOF or newline character. */
      while ((c = getchar()) != '\n' && c != EOF)
      {
        s[i++] = c;
        s = realloc(s, i + 1); // Add space for another character to be read.
      }
      s[i] = '\0';

      printf("Entered string: \t%s\n", s);
      len += (strlen(s) - 1);
      if (Graph_expand(&graph, len))
        puts("Expansion succeeded");
      printf("%zu\n", graph->nodes);
      int index_s = s[0] - '0';
      Node_delete_list(&(graph->head[index_s]));

      int src1 = s[0] - '0';
      for (int i = 1; i < strlen(s); i += 2)
      {
        int dest1 = s[i] - '0';
        int weight1 = s[i + 1] - '0';
        addEdge(&(graph->head[src1]), dest1, weight1);
      }

      printGraph(graph, len);
    }
    if (user_input == 'D')
    {
      int input_d;
      scanf("%d", &input_d);
      // int yen=Node_delete(graph, 3);
      Node_delete_list(&(graph->head[input_d]));
      for (int i = 0; i < graph->nodes; i++)
      {
        // deleteNode(&(graph->head[i]), input_d);
        Node_delete(graph, input_d);
      }
      printGraph(graph, len);
    }
    if (user_input == 'S')
    {
      int user_input_1, user_input_2;
      scanf("%d %d", &user_input_1, &user_input_2);
      int mat_i = 0, mat_j = 0;
      //int adjMatrix[len][len];
      int **adjMatrix;
      /* allocate the array */
      adjMatrix = malloc(len * sizeof *adjMatrix);
      for (int i = 0; i < len; i++)
      {
        adjMatrix[i] = malloc(len * sizeof *adjMatrix[i]);
      }

      for (int mat_i = 0; mat_i < len; mat_i++)
      {
        for (int mat_j = 0; mat_j < len; mat_j++)
        {
          adjMatrix[mat_i][mat_j] = 0;
        }
      }
      for (int i = 0; i < len; i++)
      {
        // print current vertex and all its neighbors
        struct Node *ptr = graph->head[i];
        while (ptr != NULL)
        {
          // printf("%d —> %d (%d)\t", i, ptr->dest, ptr->weight);
          adjMatrix[i][ptr->dest] = ptr->weight;
          ptr = ptr->next;
        }
      }
      int row, columns;
      for (row = 0; row < len; row++)
      {
        for (columns = 0; columns < len; columns++)
        {
          printf("%d     ", adjMatrix[row][columns]);
        }
        printf("\n");
      }

      int shortest_path = Dijkstra(adjMatrix, len, user_input_1, user_input_2);
      if (shortest_path != INFINITY)
        printf("%d\n", shortest_path);
      else
        printf("-1\n");
    }
  }
  return 0;
}