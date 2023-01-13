/*����ͷ���ĵ���������
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

List Reverse(List L){
    if(L==NULL){        //���ǵ�����Ϊ�յ����������ͷ���Ļ��Ͳ�����֣�
        return NULL;
    }
    List newlist=L;
    List current=L->Next;
    List next;
    newlist->Next=NULL;
    while(current!=NULL){
        next=current->Next;
        current->Next=newlist;
        newlist=current;
        current=next;
    }
    return newlist;
}

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

