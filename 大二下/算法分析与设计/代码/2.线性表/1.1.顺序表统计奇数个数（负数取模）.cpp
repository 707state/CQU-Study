/*˳���ͳ������������
��Ŀ������Ҫ��ʵ��һ��������Ҫ�󷵻�˳����������ĸ������ձ���0��
�����ӿڶ��壺int OddNumber(SqList L)
���룺������1�У�������-1������˳���Ԫ�أ�������������-1������˳���Ԫ�أ�����������֮���ÿո�ָ���
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
    ElemType *elem;             //int��ָ�룬��ʾint�����飬֧���±�����
    int length;
}SqList;
void InitList(SqList &L);
int OddNumber(SqList L);
//д�뺯��
int OddNumber(SqList L){
    int sum=0;
    for(int i=0;i<L.length;i++){
        if(L.elem[i]%2!=0){     //����ȡģ����+-1��Ҳ����L.elem[i]+10000000000)%2==1��������2�֣�8��0 6�֣�
            sum+=1;
        }
    }
    return sum;
}

int main()
{
    SqList L;
    InitList(L);
    printf("The number of odd numbers is %d.\n", OddNumber(L));
    return 0;
}