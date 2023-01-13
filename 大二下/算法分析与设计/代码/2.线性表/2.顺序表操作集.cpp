/*˳��������
��Ŀ������Ҫ��ʵ��˳���Ĳ�����
    �������������Ķ���Ϊ��
    List MakeEmpty()������������һ���յ����Ա�
    Position Find( List L, ElementType X )���������Ա���X��λ�á����Ҳ����򷵻�ERROR��
    bool Insert( List L, ElementType X, Position P )����X������λ��P������true�����ռ�������
���ӡ��FULL��������false���������Pָ��Ƿ�λ�ã����ӡ��ILLEGAL POSITION��������false��
    bool Delete( List L, Position P )����λ��P��Ԫ��ɾ��������true��������Pָ��Ƿ�λ�ã����
ӡ��POSITION P EMPTY��������P�ǲ���ֵ��������false��
*/
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
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
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

//��������
List MakeEmpty(){
//  struct LNode ln;                    //���ܷ��ؾֲ������ĵ�ַ����Ҫnew��C��Ϊmalloc��һ����ַ
    List ln=(List)malloc(sizeof(struct LNode));
//  ElementType *data=NULL;             //���鲻��Ҫ��ֵ�ĳ�ʼ�����ý��в���
//  data=(ElementType *)malloc(sizeof(ElementType)*MAXSIZE);
//  ln->Data=data;                      //error: assignment to expression with array type
    ln->Last=ERROR;
    return ln;
}
Position Find( List L, ElementType X ){
    for(int i=0;i<=L->Last;i++){
        if(X==L->Data[i])   return i;
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
    if(L->Last==MAXSIZE-1){
        printf("FULL");
        return false;
    }
    //else if(P>=MAXSIZE||P<0){         //����L->Last+1�����Ϸ�
    else if(P>L->Last+1||P<0){
        printf("ILLEGAL POSITION");
        return false;
    }
    for(int i=L->Last;i>=P;i--){
        L->Data[i+1]=L->Data[i];
    }
    L->Data[P]=X;
    L->Last++;
    return true;
}
bool Delete( List L, Position P ){
    if(P>L->Last||P<0){
        printf("POSITION %d EMPTY",P);
        return false;
    }
    for(int i=L->Last;i>P;i--){
        L->Data[i-1]=L->Data[i];
    }
    L->Last--;
    return true;
}

