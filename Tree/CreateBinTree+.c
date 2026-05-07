#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); 
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

BinTree CreatBinTree(){
    ElementType x;
    scanf(" %c",&x);
    if(x=='@'){
        return NULL;
    }
    BinTree BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Data = x;
    BT->Left = CreatBinTree();
    BT->Right = CreatBinTree();
    return BT;
}

void LevelorderTraversal( BinTree BT )
{
    if(!BT){
        return;
    }
    BinTree queue[1000];
    int front = 0,rear = 0;

    queue[rear++]=BT;

    while(front<rear){
        BinTree t = queue[front++];
        printf("%c",t->Data);
        if(t->Left){
            queue[rear++] = t->Left;
        }
        if(t->Right){
            queue[rear++] = t->Right;
        }
    }
    

}


int main()
{   
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        BinTree BT = CreatBinTree();
        LevelorderTraversal(BT);
        printf("\n");
    }
    
    return 0;
}