#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef int Element;

struct stack{
    Element Data[MaxSize];
    int top;
};

typedef struct stack Stack;

void Init_Stack(Stack *s){
    //stack *s = (Stack*)malloc(sizeof(Stack));
    //s->data = (Element*)malloc(MaxSize*sizeof(Element));
    s->top = -1;
}

int isEmpty(Stack *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack *s){
    if(s->top==MaxSize-1){
        return 1;
    }else{
        return 0;
    }
}

int push(Stack *s,Element x){
    if(isFull(s)){
        return 0;
    } 
    s->top++;
    s->Data[s->top] = x;
    return 1;
}

int pop(Stack *s,Element *x){
    if(isEmpty(s)){
        return 0;
    }
    *x = s->Data[s->top];
    s->top--;
    return 1;
}
int  Stack_print(Stack *s){
    if(isEmpty(s)){
        return 0;
    }
    Element x;
    while(!isEmpty(s)){
        x = s->Data[s->top];
        printf("%d ",x);
        s->top--;

    }
    printf("\n");
    return 1;
}

int getTop(Stack *s,Element *e){
    if(isEmpty(s)){
        return 0;
    }
    *e = s->Data[s->top];
    return 1;
}
int main(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    Init_Stack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    Element x;
    pop(s,&x);
    printf("%d\n",x);
    
    Element e;
    getTop(s,&e);
    printf("%d\n",e);
    Stack_print(s);
    return 0;
}