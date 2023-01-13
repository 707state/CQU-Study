/*����������:
��Ŀ�����д����Reverse����������ͷ���ĵ��������á�
˵����Create �������ڴ�������Destroy ����������������Input ������������������������������
Ȼ��������Щ����Ԫ�ء�Output ���������������������Ԫ��֮���Կո�����
ע������ĵ�����ָ��ͷ���ĵ������磺head->5->3->9->NULL��������ú���head->9->3->5->NULL
*/
#include <iostream>
using namespace std;

typedef struct _NODE_{
    int data;
    struct _NODE_ *next;
} NODE;

void Reverse(NODE *head){
    NODE* current=head->next;   //�˴��������б�ͷ����˴���һλ��ʼȡ
    NODE* tmp;
    //head����ָԭ����ı�ͷ����ָ����������ĵ�һ����㣬ͬ������ʹ�ж��������µ���
    head->next=NULL;            //��������ı�ͷ�������Ͽ�����Ϊ������Ľ�β
    while(current!=NULL){       //tmpָ��ԭ����ı�ͷ
        tmp=current;            //�洢current
        current=current->next;  //current�����
        //�˴����������б�ͷ
        tmp->next=head->next;   //�������һ������nextָ��ָ��������ĵ�һ�����
        head->next=tmp;         //headָ��ָ��������ı�ͷ
    }
}

int main(){
    NODE *h;
    Create(&h);
    Input(h);
    Reverse(h);
    Output(h);
    putchar('\n');
    Destroy(&h);
    return 0;
}