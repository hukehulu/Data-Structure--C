#include "stdio.h"
#include "stdlib.h"

typedef  int ElementType;

struct node{
    ElementType Data;
    struct node* next;
};

typedef struct node List;
List* Init_List(){
    List *head = (List*)malloc(sizeof(List));
    head->Data = 0;
    head->next = NULL;
    return head;
}

int Insert_List(List *L,ElementType x){
    List *p = (List*)malloc(sizeof(List));
    p->Data = x;
    p->next = L->next;
    L->next = p;
    return 0;
}

void ListNode(List *L){
    List *p = L->next;
    while(p!=NULL){
        printf("%d ",p->Data);
        p = p->next;
    }
    printf("\n");
}

void List_Insert(List *L,ElementType x){
    List *p = (List*)malloc(sizeof(List));
    p->Data = x;
    while(L->next!=NULL){
        L = L->next;
    }
    L->next = p;
    p->next = NULL;
}

void List_Delete(List *L,ElementType x){
    List *p = L->next;
    List *q;
    while(p!=NULL){
        if(p->next->Data==x){
            q = p->next;
            p->next = q->next;
            free(q);
            break;
        }
        
        p = p->next;
    }
}

List* Reverse(List *L){
    List *first =NULL;
    List *second = L->next;
    List *third;
    while(second!=NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    List *newHead = Init_List();
    newHead->next = first;
    return newHead;
}

int findNodeFS(List *L,ElementType k){
    List *fast = L->next;
    List *slow = L->next;
    for(int i=0;i<k;i++){
        fast = fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    printf("Reverse-%d Num is %d\n",k,slow->Data);
    return 1;
}

int main(){
    List *head = Init_List();
    Insert_List(head,1);
    Insert_List(head,2);
    Insert_List(head,3);

    List_Insert(head,4);
    List_Insert(head,5);
    ListNode(head);
    List_Delete(head,4);
    ListNode(head);
    findNodeFS(head,2);
    ListNode(head);
    List *reverse = Reverse(head);
    ListNode(reverse);
    return 0;
}