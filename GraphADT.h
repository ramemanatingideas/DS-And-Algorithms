#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>


struct Node {
  struct Node *next;
  int vertex;
};

struct Graph {
  bool *visited;
  struct Node** AdjList;
  int numVertices;
};

struct Node* createNode(int);
struct Graph* createGraph(int);
void addEdge(struct Graph* ,int ,int);
void DFS(struct Graph*,int);
void printGraph(struct Graph*);

// int main(int argc, char const *argv[]) {
//   struct Graph* graph = createGraph(5);
//      addEdge(graph, 0, 1);
//      addEdge(graph, 0, 4);
//      addEdge(graph, 1, 2);
//      addEdge(graph, 1, 3);
//      addEdge(graph, 1, 4);
//      addEdge(graph, 2, 3);
//      addEdge(graph, 3, 4);
//
//    DFS(graph,2);
//
//    printGraph(graph);
// }

struct Node* createNode(int n){
  struct Node* newNode = malloc(sizeof(struct Node));
  if (!newNode) {
    return NULL;
  }
  newNode->vertex = n;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices){
  struct Graph* newGraph = malloc(sizeof(struct Graph));
  if(!newGraph){
    return NULL;
  }
  newGraph->numVertices = vertices;
  newGraph->AdjList = malloc(vertices * sizeof(struct Node*));
  newGraph->visited = malloc(vertices * sizeof(bool));
  for (size_t i = 0; i < vertices; i++) {
    newGraph->AdjList[i] = NULL;
    newGraph->visited[i] = false;
  }

  return newGraph;
}

void addEdge(struct Graph* graph ,int src,int dest )
{
    struct Node* newNode = createNode(dest);

    newNode->next = graph->AdjList[src];
    graph->AdjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->AdjList[dest];
    graph->AdjList[dest] = newNode;


}

void printGraph(struct Graph* graph){
  for (size_t i = 0; i < graph->numVertices; i++) {
      struct Node* temp =  graph->AdjList[i];
      while(temp){
        printf("%d ->",temp->vertex );
        temp = temp->next;
      }
      printf("\n");
  }
}

void DFS(struct Graph* graph,int v){
  struct Node *newNode = graph->AdjList[v];
  struct Node *temp = newNode;
  graph->visited[v] = true;
  printf("Visited the vertex %d\n",v);
  while(temp!=NULL){
    int vertexConnected = temp->vertex;
      if(graph->visited[vertexConnected] ==false){
        DFS(graph,vertexConnected);
      }
      temp = temp->next;
  }

}
