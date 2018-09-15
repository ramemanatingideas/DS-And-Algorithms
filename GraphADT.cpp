// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
//
// struct Graph {
//   int v;
//   int e;
//
//   //for adjacency matrix representaiton
//   int **AdjMatrix;
//
//   //for adjacenct list representation
// //  int *AdjList;
// };
//
// struct ListNode{
//   int vertexNumber;
//   struct ListNode *next;
// };
//
// //Adjacency List representation
// /*
// struct Graph *AdjacencyList(){
//
//   int u,v;
//
//   struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
//   if(!G){
//     printf("Memory Error");
//     return;
//   }
//
//   scanf("Enter the number of vertices %d and edges %d" ,&G->v , &G->e);
//   G->AdjList =  malloc(G->v * sizeof(struct ListNode));
//
//   for (size_t i = 0; i < G->v; i++) {
//     G->AdjList[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
//     G->AdjList[i]->vertexNumber = i;
//     G->AdjList[i]->next = G->AdjList[i];
//   }
//
//   for (size_t i = 0; i < G->e; i++) {
//       scanf("Enter Edge %d %d",&u,&v);
//       temp = (struct ListNode*)malloc(sizeof(ListNode));
//       temp->vertexNumber = v;
//       temp->next = G->AdjList[u];
//       G->AdjList[u]->next = temp;
//       temp = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//       temp->vertexNumber = v;
//       temp->next = G->AdjList[v];
//       G->AdjList[v]->next = temp;
//
//
//   }
//
//   return G;
// }
// */
// int sizeofall;
// //Adjacency Matrix representaiton
// struct Graph *AdjacencyMatrix(){
//
//   int i,u,v;
//   struct Graph *G = (struct Graph*) malloc(sizeof(struct Graph));
//
//   if(!G){
//     printf("Memory Error \n");
//     return 0;
//   }
//
//   printf("Enter the number of vertices and edges\n");
//   scanf("%d %d ", &G->v , &G->e );
//   sizeofall = v;
//
//   G->AdjMatrix = malloc(sizeof( G->v * G->v ));
//
//   for(int i=0; i<G->v; i++)
//   {
//       for (size_t j = 0; j < G->v; j++) {
//         G->AdjMatrix[j][j] = 0;
//       }
//   }
//
//   for (size_t i = 0; i < G->e; i++) {
//     printf("Enter the edges to the vertices u and v\n");
//     scanf("%d %d ",&u,&v);
//
//     G->AdjMatrix[u][v] = 1;
//     G->AdjMatrix[v][u] = 1;
//
//   }
//
//   return G;
//
// }
//
// //Graph traversals====
// //======DFS=======
// //  int visited[sizeofall];
// void DFS(struct Graph *G,int u){
//   visited[u] = 1;
//   printf("visited vertex %d \n",u);
//   for (size_t V = 0; V < G->v; V++) {
//       if(!visited[V] && G->AdjMatrix[u][V])
//         DFS(G,V);
//   }
//
// }
//
// void DFStraversal(struct Graph *G,int v){
//
//   for (size_t i = 0; i < G->v; i++) {
//     visited[i] = 0;
//   }
//
//   for (size_t i = 0; i < G->v; i++) {
//     if (!visited[i]) {
//       DFS(G,i);
//     }
//
//   }
// }
// //==================
//
//
// int main(int argc, char const *argv[]) {
//
// struct Graph *G;
// G = AdjacencyMatrix();
//
// DFStraversal(G,1);
//
//   return 0;
// }
