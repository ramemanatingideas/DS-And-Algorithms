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
    struct Node* temp;
    int inDeg[graph->numVertices];

    for (size_t k = 0; k < graph->numVertices; k++) {
        inDeg[k] = 0;
    }

    for (size_t i = 0; i < graph->numVertices; i++) {
      temp = graph->AdjList[i];
        while(temp){
          if(temp->next!=NULL)
            {
                inDeg[temp->vertex]++;
                printf("the vertex having indeg is %d\n",temp->vertex);
            }
            temp = temp->next;
        }
    }

    for (size_t j = 0; j < graph->numVertices; j++) {
        printf("%d ",inDeg[j]);
    }
}

void TopologicalSort(Graph* graph,int inDeg[]){
    struct Queue* Q = createQueue();
    int count=0;
    struct Node* temp;
    //if indegres are 0 then add to the queue
    for (size_t i = 0; i <graph->numVertices ; i++) {
        if(inDeg[i]==0)
          EnQueue(Q,i);
    }
    int u;
    //decrement the indegress when remving and add to the queue when indegree is 0
    while (!IsQueueEmpty()) {
      u = Dequeue(Q);//remove the previous ones having indegree 0
      for (size_t i = 0; i < u; i++) {
          if(--inDeg[i]==0){
            EnQueue(Q,i);//add to the queue
          }
      }
    }
}

int main(int argc, char const *argv[]) {
  //struct Graph* graph = createGraph(6);
  struct Graph* graph2 = createGraph(8);
    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 2);
    // addEdge(graph, 3, 2);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 2, 4);
    // addEdge(graph, 3, 4);

     //printGraph(graph);
    //BFS(graph, 0);

    addEdge_directed(graph2,3,7);
    addEdge_directed(graph2,2,7);
    addEdge_directed(graph2,7,0);
    addEdge_directed(graph2,7,5);
    addEdge_directed(graph2,4,5);
    addEdge_directed(graph2,7,6);
    addEdge_directed(graph2,1,6);
    addEdge_directed(graph2,1,4);
   printGraph(graph2);



   //printGraph(graph);
   Find_Indegress(graph2);
}
