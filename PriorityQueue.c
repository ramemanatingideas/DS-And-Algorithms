#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct MinHeap{
  int nodes_size;
  int cap;
  int *position;
  struct MinHeap **array;
};

struct MinHeapNode{
  int distance;
  int v;
};

struct heap* createHeap(int capacity){
  struct MinHeap* Heap  =(struct MinHeap*) malloc(sizeof(struct MinHeap));
  Heap->cap = capacity;
  Heap->nodes_size = 0;
  Heap->position = (int *) malloc(sizeof(int));

  Heap->array = (struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode* ));

  return Heap;
}

struct MinHeapNode* createHeapNode(int v,int dist){

  struct MinHeapNode *HeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
  HeapNode->distance = dist;
  HeapNode->v = v;

  return HeapNode;

}

void swapNodes(struct MinHeapNode** a ,struct MinHeapNode** b){
  struct MinHeapNode* tempNode = NULL;
  tempNode = *b;
  *b = *a;
  *a = tempNode;
}

void minHeapify(struct MinHeap* minHeap,int index){
  int left = 2*index+1;
  int right = 2*index+2;
  int smallest = index;

  if (left < minHeap->nodes_size && minHeap->array[left]->distance < array[smallest]->distance) {
    smallest = minHeap->array[left];
  }

  if (right < minHeap->nodes_size && minHeap->array[right]->distance < array[smallest]->distance) {
    smallest = minHeap->array[right];
  }

  if(smallest!=index){
    struct MinHeapNode* smallestNode = minHeap->array[smallest];
    struct MinHeapNode* indexNode = minHeap->array[index];

    minHeap->position[smallestNode->v] = index;
    minHeap->position[indexNode->v] = smallest;

    swapNodes(&smallestNode,&indexNode);

    minHeapify(minHeap,smallest);
  }
}

bool isEmpty(struct MinHeap *heap){
  return heap->nodes_size==0;
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap){

  if(isEmpty(minHeap))
    return NULL;

//extract root
  struct MinHeapNode* root = minHeap->array[0];
//swap lastnode and the root
  struct MinHeapNode* LastNode = minHeap->array[nodes_size-1];
  minHeap->array[0] = LastNode;

  //update pos of last node
  minHeap->position[LastNode->v] = 0;
  minHeap->position[root->v] = minHeap->nodes_size;

  --minHeap->nodes_size;

  minHeapify(minHeap,0);

  return root;
}

bool IsInMinHeap(struct MinHeap* minHeap,int v){
  if(minHeap->position[v] < minHeap->nodes_size)
    return true;
}
