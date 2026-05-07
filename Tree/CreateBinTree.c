#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
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
    scanf("%d",&x);
    if(x==0){
        return NULL;
    }
    BinTree BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Data = x;
    BT->Left = CreatBinTree();
    BT->Right = CreatBinTree();
    return BT;
}
void InorderTraversal( BinTree BT )
{
    if (BT) {
        InorderTraversal(BT->Left);
        printf(" %d", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal( BinTree BT )
{
    if (BT) {
        printf(" %d", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal( BinTree BT )
{
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %d", BT->Data);
    }
}



int main()
{
    BinTree BT = CreatBinTree();
    InorderTraversal(BT);    printf("\n");
    PreorderTraversal(BT);   printf("\n");
    PostorderTraversal(BT);  printf("\n");
    return 0;
}