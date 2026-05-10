#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int Element;

struct queue{
    Element Data[MaxSize];
    int Front;
    int Rear;
};

typedef struct queue Queue;

Queue* Init_Queue(){
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    Q->Front=0;
    Q->Rear=0;
    return Q;
}

int isEmpty(Queue *Q){
    if(Q->Front==Q->Rear){
        return 1;
    }else{
        return 0;
        
    }
}

int isFull(Queue *Q){
    if(Q->Front>0){
        int set = Q->Front;
        for(int i=Q->Front;i<Q->Rear;i++){
            Q->Data[i-set] = Q->Data[i];
        }
        Q->Front = 0;
        Q->Rear = Q->Rear-set;
        return 0;
    }else{
        return 1;
    }

}

int dequeue(Queue *Q){
    if(isEmpty(Q)){
        return 0;
    }
    Element x = Q->Data[Q->Front];
    Q->Front++;
    return x;
}

int enqueue(Queue *Q,Element x){
    if(Q->Rear>=MaxSize){
        if(isFull(Q)){
            return 0;
        }
    }
    Q->Data[Q->Rear] = x;
    Q->Rear++;
    return 1;
}

int getFront(Queue *Q,Element *x){
    if(isEmpty(Q)){
        return 0;
    }
    *x = Q->Data[Q->Front];
    return 1;
}
int main(){
    Queue *Q = Init_Queue();
    enqueue(Q,1);
    enqueue(Q,2);
    enqueue(Q,3);
    Element x;
    getFront(Q,&x);
    printf("%d\n",x);
    int y = dequeue(Q);
    getFront(Q,&y);
    printf("%d\n",y);
    return 0;
}
