#include <stdio.h>
#include <stdlib.h>


typedef int Element;

struct stack{
    Element Data;
    struct stack *next;
};

typedef struct stack Stack;

Stack* Init_Stack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->Data = 0;
    s->next = NULL;
    return s;
}

int isEmpty(Stack *s){
    if(s->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

int push(Stack *s,Element x){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->Data = x;
    p->next = s->next;
    s->next = p;
    return 1;
}

int pop(Stack *s,Element *x){
    if(isEmpty(s)){
        return 0;
    }
    Stack *q = s->next;
    *x = q->Data;
    s->next = q->next;
    free(q);
    return 1;
}

int getTop(Stack *s,Element *x){
    if(isEmpty(s)){
        return 0;
    }
    *x = s->next->Data;
    return 1;
}

int main(){
    Stack *s = Init_Stack();
    push(s,1);
    push(s,2);
    push(s,3);
    Element x;
    getTop(s,&x);
    printf("%d\n",x);
    pop(s,&x);
    printf("%d\n",x);
    return 0;
}
