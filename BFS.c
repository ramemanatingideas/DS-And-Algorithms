#include "GraphADT.h"
#include <stdio.h>
#include<stdbool.h>
#include "Queue.h"

void BFS(struct Graph* graph,int v){
  struct Queue* q = createQueue();
  graph->visited[v] = true;
  EnQueue(q,v);

  while (!IsQueueEmpty(q)) {
    int currVertex = Dequeue(q);
    printf("%d -> ",currVertex);

    struct Node* temp = graph->AdjList[currVertex];
    while (temp) {
      int index = temp->vertex;
        if(graph->visited[index]!=true){
          graph->visited[index]=true;
          EnQueue(q,index);
        }
        temp = temp->next;
    }
  }

}

void Find_Indegress(struct Graph* graph){
    struct Node* temp = graph->AdjList[0];
    int inDeg[graph->numVertices];
    while(temp){
      if(temp->next!=NULL)
          
    }
}


int main(int argc, char const *argv[]) {
  struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

   //printGraph(graph);
}
