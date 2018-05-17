#include "GraphADT.h"
#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void BellmanFord(struct Graph* graph,int source,int n,int weightMatrix[][n]){
    int distance[graph->numVertices];
    for (size_t i = 0; i < graph->numVertices; i++) {
        distance[i] = 999;
    }
    struct Queue* Q = createQueue();
    distance[source] = 0;
    EnQueue(Q,source);

    int v,d=0,PATH[graph->numVertices];
    struct Node* temp = NULL;
    while(!IsQueueEmpty(Q)){
      v = Dequeue(Q);
      temp = graph->AdjList[v];

      while (temp) {
        d = distance[v] + weightMatrix[v][temp->vertex];
        if(d < weightMatrix[v][temp->vertex]){
          distance[v] = d + weightMatrix[v][temp->vertex];
          PATH[temp->vertex] = v;
          EnQueue(Q,temp->vertex);
        }
        temp = temp->next;
      }

    }

    for (size_t i = 0; i < graph->numVertices; i++) {
        printf("%d ",PATH[i]);
    }
}

int main(int argc, char const *argv[]) {
  struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    int weightMatrix[5][5] ={
      {0,4,1,999,999},
      {4,0,2,999,4},
      {1,2,0,4,999},
      {999,999,999,0,4},
      {999,4,999,4,0}
    };

    BellmanFord(graph,0,5,weightMatrix);

  return 0;
}
