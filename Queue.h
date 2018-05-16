#include <stdio.h>
#include<stdlib.h>
struct ListNode{
  int value;
  struct ListNode *next;
};

struct Queue{
  struct ListNode *rear;
  struct ListNode *front;
};

struct Queue* createQueue(){
  struct Queue* Q = malloc(sizeof(struct Queue));
  if(!Q){
    return NULL;
  }

  struct ListNode* node = malloc(sizeof(struct ListNode));
  if(!node){
    return NULL;
  }
  Q->rear = NULL;
  Q->front = NULL;

  return Q;

}

void EnQueue(struct Queue* q, int val){
  struct ListNode* temp = malloc(sizeof(struct ListNode));
  if(!temp){return NULL;}

  temp->value  = val;
  temp->next = NULL;

  if(q->rear)q->rear->next = temp;
  q->rear = temp;


  if (q->front == NULL) {
    q->front = q->rear;
  }
}

int IsQueueEmpty(struct Queue* Q){
  return(Q->front==NULL);
}

int Dequeue(struct Queue* Q){
  struct ListNode* temp = malloc(sizeof(struct ListNode));
    int val = 0;
  if(!temp)
    return NULL;
    temp->next = NULL;

  if(!IsQueueEmpty(Q)){
    temp = Q->front;
    val = Q->front->value;
    Q->front = Q->front->next;
    free(temp);
  }

  else{
    printf("Queue is Empty\n");
    return 0;
  }

  return val;

}
