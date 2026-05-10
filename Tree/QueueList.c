#include <stdio.h>
#include <stdlib.h>

typedef int Element;

struct queuenode{
    Element Data;
    struct queuenode *next;
};

typedef struct queuenode Queuenode;

typedef struct{
    Queuenode *Front;
    Queuenode *Rear;
} Queue;

Queue* InitQueue(){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Queuenode *node = (Queuenode*)malloc(sizeof(Queuenode));
    node->Data = 0;
    node->next = NULL;
    Q->Front = node;
    Q->Rear = node;
    return Q;
}

int isEmpty(Queue *Q){
    if(Q->Front==Q->Rear){
        return 1;
    }else{
        return 0;
    }
}

int enQueue(Queue *Q, Element e){
    Queuenode *node = (Queuenode*)malloc(sizeof(Queuenode));
    node->Data = e;
    node->next = NULL;
    Q->Rear->next = node;
    Q->Rear = node;
    return 1;
}

int deQueue(Queue *Q, Element *x){
    if(isEmpty(Q)){
        return 0;
    }
    Queuenode *q = Q->Front->next;
    *x = Q->Front->next->Data;
    Q->Front->next = q->next;
    if(Q->Rear == q){
        Q->Rear = Q->Front;
    }
    free(q);
    return 1;
}

int getFront(Queue *Q, Element *x){
    if(isEmpty(Q)){
        return 0;
    }
    *x = Q->Front->next->Data;
    return 1;
}
int main(){
    Queue *Q = InitQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    Element x;
    getFront(Q, &x);
    printf("%d\n", x);
    deQueue(Q, &x);
    printf("%d\n", x);
    getFront(Q, &x);
    printf("%d\n", x);
    return 0;
}