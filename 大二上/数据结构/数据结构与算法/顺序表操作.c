#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
List MakeEmpty(){
    List makePtr;
    makePtr=(List)malloc(sizeof(List));
    makePtr->Last=-1;
    return makePtr;
}
Position Find( List L, ElementType X ){
    Position i;
    while(i<=L->Last&&L->Data[i]!=X){
        i++;
    }
    if(i>L->Last) return -1;
    else return i;
}
bool Insert( List L, ElementType X, Position P ){
    int j;
    if(L->Last==MAXSIZE-1){
        printf("表满");
        return 0;
    }if(P<1||P>L->Last+2){
        printf("位置不合法");
        return 0;
    }
    for(j=L->Last;j>=P-1;j--){
        L->Data[j+1]=L->Data[j];
    }
    L->Data[P-1]=X;
    L->Last++;
    return 1;
}
bool Delete( List L, Position P ){
    int j;
    if(P<1||L->Last+1<P){
        printf("不存在第%d个元素",P);
        return 0;
    }
    for(j=P;j<=L->Last;j++){
        L->Data[j-1]=L->Data[j];
    }
    L->Last--;
    return 1;
}